# from sshtunnel import SSHTunnelForwarder
# import psycopg2
#
# eq = "16x^2 -40x + 9"
# eq = eq.replace('x', '')
# eq = eq.replace('^2', '')
# eq = eq.replace(' ', '')
# # If the character is at i!= () plus breakpoint
#
# eq = eq.split(' ')
# print(eq)
#
#
# # Your full PostgreSQL connection URL
# DB_URL = "postgres://db_url"
#
# with SSHTunnelForwarder(
#     ('target_site', 22),
#     ssh_username='username',
#     ssh_pkey='~/.ssh/id_rsa',  # Or use ssh_password='your_password'
#     remote_bind_address=('localhost', 5432),
#     local_bind_address=('localhost', 5433)
# ) as tunnel:
#     conn = psycopg2.connect(DB_URL, connect_timeout=5)
#
#     cur = conn.cursor()
#     cur.execute("SELECT NOW();")
#     print(cur.fetchone())
#     cur.close()
#     conn.close()

import os
from flask import Flask, send_from_directory

app = Flask(__name__)

# Folder where test files live
TEST_FILES_DIR = os.path.join(os.path.dirname(__file__), "test_files")
os.makedirs(TEST_FILES_DIR, exist_ok=True)


@app.route("/files/<path:filename>")
def serve_file(filename):
    """
    Example: http://127.0.0.1:5000/files/sample.txt
    """
    return send_from_directory(TEST_FILES_DIR, filename, as_attachment=True)


if __name__ == "__main__":
    # Put a file into test_files/sample.txt first
    app.run(host="0.0.0.0", port=5000, debug=True)
