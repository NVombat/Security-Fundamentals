import socket, sys

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

host = socket.gethostname()
port = 8080

client.connect((host,port))

while True:
    msg = input("Enter Your Message to the Server: ")
    if msg == "bye":
        break
    msg = bytes(msg, 'utf-8')
    client.sendall(msg)

print("Client is offline")
client.close()