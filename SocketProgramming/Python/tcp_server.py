import socket, sys

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

host = socket.gethostname()
port = 8080

server.bind((host, port))

server.listen()

conn, addr = server.accept()
print("Connected By: ", addr)

while True:
    data = conn.recv(1024)
    if not data:
        break
    else:
        print("Received Message: ", data)

print("Server is offline")
server.close()
