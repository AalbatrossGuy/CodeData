# Created by AG on 31-08-2025

import os
import sys
import re
import click
import numpy
import psycopg
from groq import Groq
from psycopg.rows import dict_row
from dataclasses import dataclass
from typing import List, Tuple, Dict, Iterable, Generator, Optional
from pgvector.psycopg import register_vector
from sentence_transformers import SentenceTransformer
import xml.etree.ElementTree as ET


@dataclass
class Chunk:
    id: str
    content: str
    metadata: Dict[str, int]


def _iter_content_text(xml_path: str) -> Generator[str, None, None]:
    # Stream parse; clear elements to keep memory flat
    for _, elem in ET.iterparse(xml_path, events=("end",)):
        if elem.tag.rsplit('}', 1)[-1].lower() == "content":
            parts = []
            for t in elem.itertext():
                if t and (s := t.strip()):
                    parts.append(s)
            if parts:
                yield " ".join(parts)
        elem.clear()


def _normalize(s: str) -> str:
    # Fast whitespace compaction; avoids huge regex over mega-strings
    return re.sub(r"\s+", " ", s).strip()


def iter_chunks_from_xml(
    xml_file_path: str,
    max_characters: int = 500,
    intersections: int = 100
) -> Generator[Chunk, None, None]:
    block_idx = 0
    for raw in _iter_content_text(xml_file_path):
        text = _normalize(raw)
        if not text:
            block_idx += 1
            continue
        n = len(text)
        if max_characters <= 0:
            max_characters = 500
        if intersections < 0 or intersections >= max_characters:
            intersections = max(0, max_characters // 5)
        step = max_characters - intersections if max_characters > intersections else max_characters

        idx = 0
        while idx < n:
            end = idx + max_characters
            slice_ = text[idx:end]
            cid = f"C{block_idx:06d}-O{idx:08d}"
            yield Chunk(
                id=cid,
                content=slice_.strip(),
                metadata={"page": block_idx, "character_offset": idx}
            )
            if end >= n:
                break
            idx += step
        block_idx += 1


class VectorDBStore:
    def __init__(self, url: str, table: str = "chunks", text_dim: int = 384):
        self.url = url
        self.table = table
        self.dim = text_dim
        self._verify_schema()

    def _verify_schema(self):
        with psycopg.connect(self.url, autocommit=True) as connection:
            with connection.cursor() as cursor:
                cursor.execute("CREATE EXTENSION IF NOT EXISTS vector;")
                cursor.execute(
                    f"""
                    CREATE TABLE IF NOT EXISTS {self.table} (
                        chunk_id TEXT PRIMARY KEY,
                        page INTEGER NOT NULL,
                        character_offset INTEGER NOT NULL,
                        content TEXT NOT NULL,
                        text_embedding VECTOR({self.dim}) NOT NULL
                    );
                    """
                )
                cursor.execute(
                    f"""
                    DO $$
                    BEGIN
                        IF NOT EXISTS(
                            SELECT 1 FROM pg_class info
                            JOIN pg_namespace name on name.oid = info.relnamespace
                            WHERE info.relname = '{self.table}_embedding_index'
                        ) THEN
                            CREATE INDEX {self.table}_embedding_index
                            ON {self.table}
                            USING ivfflat (text_embedding vector_cosine_ops)
                            WITH (lists = 100);
                        END IF;
                    END$$;
                    """
                )

    def upsert_batch(self, batch_rows: List[Tuple[str, int, int, str, list]]) -> None:
        if not batch_rows:
            return
        with psycopg.connect(self.url) as connection:
            with connection.cursor() as cursor:
                cursor.executemany(
                    f"""
                    INSERT INTO {self.table}
                        (chunk_id, page, character_offset, content, text_embedding)
                    VALUES (%s, %s, %s, %s, %s)
                    ON CONFLICT (chunk_id) DO UPDATE SET
                        page = EXCLUDED.page,
                        character_offset = EXCLUDED.character_offset,
                        content = EXCLUDED.content,
                        text_embedding = EXCLUDED.text_embedding;
                    """,
                    batch_rows
                )
            connection.commit()

    def search(
        self,
        embedded_query: numpy.ndarray,
        top_k: int = 6
    ) -> List[Tuple[Chunk, float]]:
        query_vector = embedded_query.tolist()
        with psycopg.connect(self.url, row_factory=dict_row) as connection:
            register_vector(connection)
            with connection.cursor() as cursor:
                cursor.execute(
                    f"""
                    SELECT chunk_id, page, character_offset, content,
                        (text_embedding <=> %s::vector) AS cosine_distance
                    FROM {self.table}
                    ORDER BY text_embedding <=> %s::vector
                    LIMIT %s;
                    """,
                    (query_vector, query_vector, top_k)
                )
                rows = cursor.fetchall()
        out: List[Tuple[Chunk, float]] = []
        for r in rows:
            c = Chunk(
                id=r["chunk_id"],
                content=r["content"],
                metadata={"page": r["page"], "character_offset": r["character_offset"]}
            )
            sim = float(1.0 - r["cosine_distance"])
            out.append((c, sim))
        return out


class Embed:
    def __init__(self, model: str = "sentence-transformers/all-MiniLM-L6-v2"):
        self.model = SentenceTransformer(model)
        v = self.model.encode(["validate"], normalize_embeddings=True)
        self.dim = int(v.shape[1])

    def encode_embed(self, texts: List[str], batch_size: int = 64) -> numpy.ndarray:
        arr = self.model.encode(
            texts,
            batch_size=batch_size,
            normalize_embeddings=True,
            show_progress_bar=False
        )
        return numpy.asarray(arr, dtype=numpy.float32)


class RAGRetrieverModel:
    def __init__(self, vectorStore: VectorDBStore, embedder: Embed):
        self.vectorStore = vectorStore
        self.embedder = embedder

    def search(self, query: str, top_k: int = 6) -> List[Tuple[Chunk, float]]:
        q = self.embedder.encode_embed([query])[0]
        return self.vectorStore.search(embedded_query=q, top_k=top_k)


def create_retrieve_context(ChunkBlock: List[Tuple[Chunk, float]], max_characters=1000) -> str:
    buf, used, total = [], set(), 0
    for ch, _ in ChunkBlock:
        if ch.id in used:
            continue
        line = f"[Chunk_id: {ch.id} page: {ch.metadata.get('page')}] {{\n{ch.content.strip()}\n}}\n"
        if total + len(line) > max_characters:
            break
        buf.append(line)
        used.add(ch.id)
        total += len(line)
    return "".join(buf)


def answer_pass_threshold(ChunkBlocks, min_similarity=0.14, min_support=1, support_similarity=0.06) -> bool:
    if not ChunkBlocks:
        return False
    top_similarity = ChunkBlocks[0][1]
    if top_similarity >= 0.40:
        return True
    if top_similarity < min_similarity:
        return False
    supporter = sum(1 for _, s in ChunkBlocks if s >= support_similarity)
    return supporter >= min_support


fallback = "Don't know the answer"

PROMPT = """You are a strict RAG assistant.
RULES:
- Answer ONLY using the provided CONTEXT.
- If the answer is not fully contained in CONTEXT, reply exactly:
  "I don't know from the answer."
- Keep answers concise and cite chunk IDs like [Chunk_id: id] inline for claims
"""

CONTEXT_WITH_QUESTION = """QUESTION:
{question}

CONTEXT (verbatim excerpts):
{context}
"""


def groq() -> Groq:
    key = os.getenv("GROQ_API_KEY")
    return Groq(api_key=key)


def chat(client: Groq, user_prompt: str, model="qwen/qwen3-32b") -> str:
    resp = client.chat.completions.create(
        model=model,
        temperature=0.1,
        messages=[{"role": "system", "content": PROMPT}, {"role": "user", "content": user_prompt}],
        reasoning_format="hidden"
    )
    return resp.choices[0].message.content.strip()


def get_response(
    query: str,
    retriever: RAGRetrieverModel,
    client: Groq,
    min_similarity=0.05,
    min_support=1,
    support_similarity=0.02
) -> str:
    blocks = retriever.search(query, top_k=6)
    if not answer_pass_threshold(blocks, min_similarity, min_support, support_similarity):
        print('could not pass answer_pass_threshold')
        return fallback
    context = create_retrieve_context(blocks, max_characters=1000)
    response = chat(client, CONTEXT_WITH_QUESTION.format(question=query, context=context))
    if fallback in response:
        print('fallback encountered')
        return fallback
    if "[Chunk_id:" not in response:
        print('Chunk_id not found in response')
        return fallback
    return response


def stream_ingest_xml(
    xml_file_path: str,
    store: VectorDBStore,
    embedder: Embed,
    max_characters: int = 500,
    intersections: int = 100,
    upsert_batch_size: int = 1000,
    embed_batch_size: int = 128
) -> int:
    total = 0
    buffer_chunks: List[Chunk] = []
    buffer_texts: List[str] = []

    def flush():
        nonlocal total, buffer_chunks, buffer_texts
        if not buffer_chunks:
            return
        embeds = embedder.encode_embed(buffer_texts, batch_size=embed_batch_size)
        rows = [
            (
                c.id,
                int(c.metadata.get("page", 0)),
                int(c.metadata.get("character_offset", 0)),
                c.content,
                embeds[i].tolist(),
            )
            for i, c in enumerate(buffer_chunks)
        ]
        store.upsert_batch(rows)
        total += len(buffer_chunks)
        buffer_chunks = []
        buffer_texts = []

    for chunk in iter_chunks_from_xml(xml_file_path, max_characters=max_characters, intersections=intersections):
        buffer_chunks.append(chunk)
        buffer_texts.append(chunk.content)
        if len(buffer_chunks) >= upsert_batch_size:
            flush()
    flush()
    return total


@click.command()
@click.argument("xml_file_path", type=click.Path(exists=True, dir_okay=False))
@click.argument("question", type=str)
@click.option("--database-url", default="postgres://aalbatrossguy:pgadmin%40123@localhost:5432/vector_db")
@click.option("--max-characters", default=500, help="Chunk window size.")
@click.option("--intersection", default=100, help="Token/char overlap per window.")
@click.option("--min-similarity", default=0.14)
@click.option("--support-similarity", default=0.06)
@click.option("--min-support", default=2)
@click.option("--skip-indexing", is_flag=True, default=False)
@click.option("--upsert-batch-size", default=1000, help="DB upsert batch size.")
@click.option("--embed-batch-size", default=128, help="Model encode() batch size.")
def script(
    xml_file_path,
    question,
    database_url,
    max_characters,
    intersection,
    min_similarity,
    support_similarity,
    min_support,
    skip_indexing,
    upsert_batch_size,
    embed_batch_size,
):
    embedder = Embed()
    store = VectorDBStore(url=database_url, text_dim=embedder.dim)

    if not skip_indexing:
        total = stream_ingest_xml(
            xml_file_path=xml_file_path,
            store=store,
            embedder=embedder,
            max_characters=max_characters,
            intersections=intersection,
            upsert_batch_size=upsert_batch_size,
            embed_batch_size=embed_batch_size
        )
        click.echo(f"Ingested chunks: {total}")

    retriever = RAGRetrieverModel(vectorStore=store, embedder=embedder)
    client = groq()
    response = get_response(
        query=question,
        retriever=retriever,
        client=client,
        min_similarity=min_similarity,
        min_support=min_support,
        support_similarity=support_similarity
    )
    click.echo(response)


if __name__ == "__main__":
    script()
