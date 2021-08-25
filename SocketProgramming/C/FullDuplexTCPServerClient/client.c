#include <stdio.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 10000

int main()
{
    int sockfd;
    char sendbuff[1024], recvbuff[1024];

    struct sockaddr_in server_addr;
    bzero(&server_addr,sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    printf("Client is running...\n");

    connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    printf("Client is connected...\n");

    pid_t pid;
    pid = fork();

    if(pid==0)
    {
        while(1)
        {
            bzero(&sendbuff, sizeof(sendbuff));
            printf("\nType message here: ");
            fgets(sendbuff, 10000, stdin);
            send(sockfd, sendbuff, strlen(sendbuff)+1, 0);
            printf("\nMessage sent!\n");
            sleep(5);
            //break;
        }
    }
    else
    {
        while(1)
        {
            bzero(&recvbuff, sizeof(recvbuff));
            recv(sockfd, recvbuff, sizeof(recvbuff),0);
            printf("\nSERVER: %s\n", recvbuff);
            sleep(5);
            //break;
        }
    }

    close(sockfd);
    printf("Client is offline...\n");
    return 0;
}