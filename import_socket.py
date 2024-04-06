import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(('0.0.0.0', 5000))  # Replace 12345 with your port number
s.listen(5)

while True:
    clientsocket, address = s.accept()
    print(f"Connection from {address} has been established!")
    msg = clientsocket.recv(1024)
    print(msg.decode("utf-8"))
    clientsocket.close()