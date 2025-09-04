import os
import re
import time
import json
import math
import hashlib
import click
import numpy as np
import psycopg
from dataclasses import dataclass
from typing import Iterable, List, Tuple, Optional
from psycopg.rows import dict_row
from pgvector.psycopg import register_vector
from sentence_transformers import SentenceTransformer
import xml.etree.ElementTree as ET

try:
    import blingfire as bf
    BLING = True
except Exception:
    BLING = False

from transformers import AutoTokenizer

@dataclass
class IngestSummary:
    total_chunks: int = 0
    mode: str = "one-shot"
    defer_ivf: bool = False
    ivf_lists: Optional[int] = None
    elapsed_sec: float = 0.0

def _tic() -> float:
    return time.perf_counter()

def _toc(t0: float) -> float:
    return time.perf_counter() - t0

def _yield_content_tags(xml_path: str) -> Iterable[str]:
    for _, elem in ET.iterparse(xml_path, events=("end",)):
        if elem.tag.rsplit('}', 1)[-1].lower() == "content":
            parts = []
            for t in elem.itertext():
                if t and t.strip():
                    parts.append(t.strip())
            if parts:
                yield " ".join(parts)
        elem.clear()

def extract_text_from_xml(xml_path: str) -> str:
    blocks = list(_yield_content_tags(xml_path))
    return "\n\n".join(blocks)

def extract_text_from_path(path: str) -> str:
    if path.lower().endswith(".xml"):
        return extract_text_from_xml(path)
    raise ValueError(f"Unsupported file type for ingestion (expected .xml): {path}")

class Chunker:
    def __init__(self):
        self.tokenizer_name = os.environ.get("TOKENIZER", "sentence-transformers/all-MiniLM-L6-v2")
        try:
            self.tokenizer = AutoTokenizer.from_pretrained(self.tokenizer_name, use_fast=True)
        except Exception:
            self.tokenizer = None
        self.max_tokens = int(os.environ.get("CHUNK_MAX_TOKENS", "320"))
        self.min_tokens = int(os.environ.get("CHUNK_MIN_TOKENS", "60"))
        self.overlap = int(os.environ.get("CHUNK_OVERLAP_TOKENS", "40"))

    def _sentences(self, text: str) -> List[str]:
        if BLING:
            return [s for s in bf.text_to_sentences(text).split("\n") if s.strip()]
        return [s.strip() for s in re.split(r"(?<=[.!?])\s+", text) if s.strip()]

    def _tok_len(self, text: str) -> int:
        if self.tokenizer:
            return len(self.tokenizer.encode(text, add_special_tokens=False))
        return max(1, len(text.split()))

    def chunk(self, text: str) -> List[str]:
        sents = self._sentences(text)
        chunks, buf, tlen = [], [], 0
        for s in sents:
            slen = self._tok_len(s)
            if tlen + slen <= self.max_tokens:
                buf.append(s); tlen += slen
            else:
                if buf:
                    chunks.append(" ".join(buf))
                if slen > self.max_tokens:
                    words = s.split()
                    start = 0
                    while start < len(words):
                        end = start + self.max_tokens
                        piece = " ".join(words[start:end])
                        chunks.append(piece)
                        if end - start >= self.overlap:
                            start = end - self.overlap
                        else:
                            start = end
                    buf, tlen = [], 0
                else:
                    if self.overlap and buf:
                        keep = []
                        tk = 0
                        for sent in reversed(buf):
                            l = self._tok_len(sent)
                            if tk + l <= self.overlap:
                                keep.insert(0, sent); tk += l
                            else:
                                break
                        buf = keep + [s]
                        tlen = sum(self._tok_len(x) for x in buf)
                    else:
                        buf, tlen = [s], slen
        if buf:
            chunks.append(" ".join(buf))
        chunks = [c for c in chunks if self._tok_len(c) >= self.min_tokens or len(chunks) == 1]
        return chunks

def load_embed_model() -> SentenceTransformer:
    name = os.environ.get("EMBED_MODEL", "sentence-transformers/all-MiniLM-L6-v2")
    return SentenceTransformer(name, device=os.environ.get("EMBED_DEVICE", "cpu"))

def db_connect(url: str):
    conn = psycopg.connect(url, row_factory=dict_row)
    register_vector(conn)
    return conn

def ensure_table(conn, table: str, dim: int):
    with conn.cursor() as cur:
        cur.execute(f"""
        CREATE TABLE IF NOT EXISTS {table} (
            doc_id TEXT NOT NULL,
            chunk_id TEXT PRIMARY KEY,
            position INTEGER NOT NULL,
            content TEXT NOT NULL,
            text_embedding vector({dim}) NOT NULL,
            created_at TIMESTAMP DEFAULT NOW(),
            updated_at TIMESTAMP DEFAULT NOW()
        );
        """)
        cur.execute(f"CREATE INDEX IF NOT EXISTS {table}_doc_pos_idx ON {table} (doc_id, position);")
        conn.commit()

def ensure_ivf_index(conn, table: str, lists: int):
    with conn.cursor() as cur:
        cur.execute(f"""
        DO $$
        BEGIN
            IF NOT EXISTS (
                SELECT 1 FROM pg_class c
                JOIN pg_namespace n ON n.oid = c.relnamespace
                WHERE c.relname = '{table}_embedding_idx'
            ) THEN
                CREATE INDEX {table}_embedding_idx
                ON {table}
                USING ivfflat (text_embedding vector_cosine_ops)
                WITH (lists = {int(lists)});
            END IF;
        END$$;
        """)
        conn.commit()

def drop_ivf_index(conn, table: str):
    with conn.cursor() as cur:
        cur.execute(f"DROP INDEX IF EXISTS {table}_embedding_idx;")
        conn.commit()

def vacuum_analyze(conn, table: str):
    with conn.cursor() as cur:
        cur.execute(f"VACUUM (VERBOSE, ANALYZE) {table};")
        conn.commit()

def analyze_only(conn, table: str):
    with conn.cursor() as cur:
        cur.execute(f"ANALYZE {table};")
        conn.commit()

def embed_texts(model: SentenceTransformer, texts: List[str]) -> np.ndarray:
    return model.encode(texts, normalize_embeddings=True, batch_size=int(os.environ.get("EMBED_BATCH", "64")), show_progress_bar=False)

def _mk_chunk_id(doc_id: str, position: int, content: str) -> str:
    h = hashlib.md5(f"{doc_id}|{position}|{content[:64]}".encode("utf-8")).hexdigest()
    return f"{doc_id}-O{position:05d}-{h[:8]}"

def upsert_chunks(conn, table: str, doc_id: str, chunks: List[str], embeds: np.ndarray, batch: int = 2000):
    rows: List[Tuple[str, str, int, str, list]] = []
    for i, (c, e) in enumerate(zip(chunks, embeds)):
        cid = _mk_chunk_id(doc_id, i, c)
        rows.append((doc_id, cid, i, c, e.tolist()))
    with conn.cursor() as cur:
        for i in range(0, len(rows), batch):
            part = rows[i:i+batch]
            cur.execute(f"BEGIN;")
            cur.executemany(
                f"""
                INSERT INTO {table} (doc_id, chunk_id, position, content, text_embedding)
                VALUES (%s, %s, %s, %s, %s)
                ON CONFLICT (chunk_id)
                DO UPDATE SET
                    content = EXCLUDED.content,
                    text_embedding = EXCLUDED.text_embedding,
                    updated_at = NOW();
                """,
                part
            )
            cur.execute("COMMIT;")

def ingest_file(file_path: str, conn, table: str, model: SentenceTransformer, chunker: Chunker, rolling: bool = False, upsert_batch: int = 2000) -> IngestSummary:
    t0 = _tic()
    raw_text = extract_text_from_path(file_path)
    if not raw_text.strip():
        return IngestSummary(total_chunks=0, mode="rolling" if rolling else "one-shot", elapsed_sec=_toc(t0))
    chunks = chunker.chunk(raw_text)
    embeds = embed_texts(model, chunks)
    doc_id = os.path.splitext(os.path.basename(file_path))[0]
    upsert_chunks(conn, table, doc_id, chunks, embeds, batch=upsert_batch)
    return IngestSummary(total_chunks=len(chunks), mode="rolling" if rolling else "one-shot", elapsed_sec=_toc(t0))

def ingest_path(input_path: str, conn, table: str, model: SentenceTransformer, chunker: Chunker, rolling: bool = False, upsert_batch: int = 2000) -> List[IngestSummary]:
    summaries = []
    if os.path.isdir(input_path):
        for root, _, files in os.walk(input_path):
            for name in files:
                if name.lower().endswith(".xml"):
                    summaries.append(ingest_file(os.path.join(root, name), conn, table, model, chunker, rolling=rolling, upsert_batch=upsert_batch))
    else:
        summaries.append(ingest_file(input_path, conn, table, model, chunker, rolling=rolling, upsert_batch=upsert_batch))
    return summaries

@click.group()
def cli():
    pass

@cli.command("ingest")
@click.argument("input_path", type=click.Path(exists=True, dir_okay=True, file_okay=True))
@click.option("--db-url", envvar="DATABASE_URL", required=True)
@click.option("--table", envvar="PGVECTOR_TABLE", default="rag_chunks", show_default=True)
@click.option("--upsert-batch", default=2000, show_default=True, type=int)
@click.option("--rolling", is_flag=True, default=False, show_default=True)
@click.option("--defer-ivf", is_flag=True, default=False, show_default=True)
@click.option("--ivf-lists", default=100, show_default=True, type=int)
@click.option("--auto-vacuum", is_flag=True, default=True, show_default=True)
@click.option("--analyze", is_flag=True, default=False, show_default=True)
def ingest_cmd(input_path, db_url, table, upsert_batch, rolling, defer_ivf, ivf_lists, auto_vacuum, analyze):
    model = load_embed_model()
    dim = model.get_sentence_embedding_dimension()
    conn = db_connect(db_url)
    ensure_table(conn, table, dim)
    if defer_ivf:
        drop_ivf_index(conn, table)
    chunker = Chunker()
    summaries = ingest_path(input_path, conn, table, model, chunker, rolling=rolling, upsert_batch=upsert_batch)
    total = sum(s.total_chunks for s in summaries)
    if not defer_ivf:
        ensure_ivf_index(conn, table, ivf_lists)
    else:
        ensure_ivf_index(conn, table, ivf_lists)
    if auto_vacuum:
        vacuum_analyze(conn, table)
    elif analyze:
        analyze_only(conn, table)
    out = {
        "files": len(summaries),
        "total_chunks": total,
        "elapsed_sec": round(sum(s.elapsed_sec for s in summaries), 3),
        "ivf_lists": ivf_lists,
        "vacuum_run": auto_vacuum,
        "rolling": rolling
    }
    print(json.dumps(out, ensure_ascii=False, indent=2))

@cli.command("query")
@click.option("--db-url", envvar="DATABASE_URL", required=True)
@click.option("--table", envvar="PGVECTOR_TABLE", default="rag_chunks", show_default=True)
@click.option("--top-k", default=5, show_default=True, type=int)
@click.option("--query-text", required=True)
def query_cmd(db_url, table, top_k, query_text):
    model = load_embed_model()
    q = model.encode([query_text], normalize_embeddings=True)[0].tolist()
    conn = db_connect(db_url)
    with conn.cursor() as cur:
        cur.execute(
            f"""
            SELECT chunk_id, doc_id, position, content,
                   (text_embedding <=> %s) AS cosine_distance
            FROM {table}
            ORDER BY text_embedding <=> %s
            LIMIT %s;
            """,
            (q, q, top_k)
        )
        rows = cur.fetchall()
    print(json.dumps(rows, ensure_ascii=False, indent=2))

if __name__ == "__main__":
    cli()
