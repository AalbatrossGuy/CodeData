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

# a = [1, 2, 3]
# try:
#     print(a[4])
# except Exception as err:
#     print("Custom Index Error Message: ", err)

import os
from dotenv import load_dotenv
load_dotenv()

print(f"Running from iPad terminal wtf = {os.getenv("NUMBER")}")







