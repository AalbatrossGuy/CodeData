FROM python:3.8-slim-buster

WORKDIR /app
COPY prac.py ./
CMD ["python3", "prac.py"]