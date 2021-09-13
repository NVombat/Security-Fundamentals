#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>

#define PORT 8050

int main()
{
    int sockfd;
    char recv_msg[1024], success_message[] = "Command Executed Successfully!\n";
    struct sockaddr_in server_addr, client_addr;
    socklen_t clientLength = sizeof(client_addr);

    if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("Socket Creation Failed\n");
        exit(EXIT_FAILURE);
    }

    printf("Server Socket Created...\n");

    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if(bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Bind Failed\n");
        exit(EXIT_FAILURE);
    }

    printf("Server is Connected Successfully...\n");

    while(1)
    {
        bzero(recv_msg, sizeof(recv_msg));
        recvfrom(sockfd, recv_msg, sizeof(recv_msg), 0, (struct sockaddr *)&client_addr, &clientLength);
        printf("Command Output: \n");
        system(recv_msg);
        printf("Command Executed\n");
        sendto(sockfd, success_message, sizeof(success_message), 0, (struct sockaddr *)&client_addr, clientLength);
    }

    close(sockfd);
    printf("Server is Offline...\n");
    return 0;
}
