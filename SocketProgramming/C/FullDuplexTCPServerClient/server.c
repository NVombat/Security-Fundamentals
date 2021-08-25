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
    int sockfd, conn;
    char recvbuff[1024], sendbuff[1024];

    struct sockaddr_in server_addr, client_addr;
    socklen_t ClientLen;
    bzero(&server_addr, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    printf("Server is running...\n");

    bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(sockfd, 5);
    printf("Server is listening...\n");

    conn = accept(sockfd, (struct sockaddr *)&client_addr, &ClientLen);

    printf("Server is connected...\n");

    pid_t pid;
    pid = fork();
    if(pid==0)
    {
        while(1)
        {
            bzero(&recvbuff, sizeof(recvbuff));
            recv(conn, recvbuff, sizeof(recvbuff), 0);
            printf("\nCLIENT : %s\n",recvbuff);
            sleep(5);
            //break;
        }
    }
    else
    {
        while(1)
        {
            bzero(&sendbuff, sizeof(sendbuff));
            printf("\nType message here: ");
            fgets(sendbuff, 10000, stdin);
            send(conn, sendbuff, strlen(sendbuff)+1, 0);
            printf("\nMessage Sent!\n");
            sleep(5);
            //break;
        }
    }

    close(sockfd);
    printf("Server is offline...\n");
    return 0;
}