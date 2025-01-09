import socket

IP_ADDR = "192.168.1.25"

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
    try:
        for port in range(6880, 6885):
            sock.connect((IP_ADDR, port))
            print(f"Port {port} is open and listening")
    except:
        print(f"Port {port} is closed")