#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8100

int main()
{
    int sockfd;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    char serverResponse[1024];
    char clientResponse[1024];

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    printf("Client is running...\n");

    connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    printf("Client is connected...\n");

    while (1)
    {
        recv(sockfd, &serverResponse, sizeof(serverResponse), 0);
        printf("\nServer message: %s \n", serverResponse);
        
        printf("\nEnter message here: ");
        scanf("%s", clientResponse);
        send(sockfd, clientResponse, sizeof(clientResponse), 0);
    }

    close(sockfd);
    printf("Client is offline...\n");
    return 0;
}