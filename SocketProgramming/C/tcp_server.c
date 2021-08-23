#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8000

int main(int argc, char const *argv[])
{
    int server_sock, conn;
    char buff[1024];
    char* msg = "Hi from Server!";
    struct sockaddr_in addr;  
  
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(PORT);

    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    bind(server_sock, (struct sockaddr *) &addr, sizeof(addr));
    listen(server_sock, 5);

    printf("Server is running...\n");

    conn = accept(server_sock, (struct sockaddr *)NULL, NULL);

    print("Server is connected...\n");

    read(conn, buff, 1024);
    printf("%s\n", buff);
    send(conn, msg, strlen(msg), 0);
    printf("Message sent...\n");

    close(server_sock);
    printf("Server closed...\n");

    return 0;
}