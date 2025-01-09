import threading
import socket
import queue

IP_ADDR = "192.168.1.25"

open_ports = []
closed_ports = []

q = queue.Queue()
for i in range(6000, 7000):
    q.put(i)

def scan():
    while not q.empty():
        port = q.get()
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
            try:
                s.connect((IP_ADDR, port))
                print(f"Port {port} is open and listening!")

                open_ports.append(port)
            except:
                print(f"Port {port} is closed")
                closed_ports.append(port)
        q.task_done()

for i in range(30):
    t = threading.Thread(target=scan, daemon=True)
    t.start()

q.join()
print("All Ports Scanned")
print("Open Ports Are:", open_ports)
print("Closed Ports Are:", closed_ports)
