#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define PORT 8000

int main()
{
    int client_sock;
    client_sock = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);


    connect(client_sock, (struct sockaddr*)&server_addr, sizeof(server_addr));

    printf("Client is connected...\n");

    char serverresponse[1024];
    recv(client_sock, &serverresponse, sizeof(serverresponse), 0);
    printf("Server message: %s\n", serverresponse);

    close(client_sock);
    printf("Client is closed...\n");
    return 0;
}