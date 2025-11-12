# sftp.py
import os
import socket
import stat
import paramiko

HOST = "127.0.0.1"
PORT = 2222
SERVE_DIR = os.path.abspath("sftp_test_files")
HOST_KEY = paramiko.RSAKey(filename="server_rsa.key")


class SimpleServer(paramiko.ServerInterface):
    def __init__(self, user="testuser", pwd="testpass"):
        self.user, self.pwd = user, pwd

    def check_auth_password(self, username, password):
        return paramiko.AUTH_SUCCESSFUL if (username == self.user and password == self.pwd) else paramiko.AUTH_FAILED

    def check_channel_request(self, kind, chanid):
        return paramiko.OPEN_SUCCEEDED if kind == "session" else paramiko.OPEN_FAILED_ADMINISTRATIVELY_PROHIBITED


class ReadOnlySFTP(paramiko.SFTPServerInterface):
    def __init__(self, server, *args, **kwargs):
        super().__init__(server)
        self.root = SERVE_DIR

    # Helpers
    def _to_fs(self, path):
        # drop leading slash and join into SERVE_DIR
        path = path.lstrip("/")
        return os.path.normpath(os.path.join(self.root, path))

    # Required methods (minimal set for read-only)
    def list_folder(self, path):
        fs = self._to_fs(path)
        try:
            items = []
            for name in os.listdir(fs):
                p = os.path.join(fs, name)
                st = os.stat(p)
                attr = paramiko.SFTPAttributes.from_stat(st)
                attr.filename = name
                items.append(attr)
            return items
        except FileNotFoundError:
            return paramiko.SFTPServer.convert_errno(2)  # ENOENT

    def stat(self, path):
        fs = self._to_fs(path)
        try:
            st = os.stat(fs)
            return paramiko.SFTPAttributes.from_stat(st)
        except FileNotFoundError:
            return paramiko.SFTPServer.convert_errno(2)

    lstat = stat  # no symlinks in this stub

    def open(self, path, flags, attr):
        fs = self._to_fs(path)
        # read-only
        if flags & (os.O_WRONLY | os.O_RDWR):
            return paramiko.SFTPServer.convert_errno(13)  # EACCES
        try:
            f = open(fs, "rb")
        except FileNotFoundError:
            return paramiko.SFTPServer.convert_errno(2)
        h = paramiko.SFTPHandle(flags=flags)
        h.readfile = f
        return h

    def realpath(self, path):
        return os.path.join("/", os.path.relpath(self._to_fs(path), self.root)).replace("\\", "/")


def serve():
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    sock.bind((HOST, PORT))
    sock.listen(100)
    print(f"SFTP server on {HOST}:{PORT}, serving {SERVE_DIR}")

    while True:
        client, addr = sock.accept()
        t = paramiko.Transport(client)
        t.add_server_key(HOST_KEY)
        server = SimpleServer()
        t.start_server(server=server)

        # Accept session channel (required before subsystems)
        chan = t.accept(20)
        if chan is None:
            print("No channel; skipping client")
            t.close()
            continue

        # Register the SFTP subsystem handler
        t.set_subsystem_handler("sftp", paramiko.SFTPServer, ReadOnlySFTP)


if __name__ == "__main__":
    serve()
