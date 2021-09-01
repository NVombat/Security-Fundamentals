#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/stat.h>

#define PORT 8058
#define SIZE 1024

void recv_file(int sockfd)
{
    int bytes_recv;
    FILE *fp;
    char *filename = "recv.txt";
    char recv_buffer[SIZE];

    fp = fopen(filename, "w");
    while (1)
    {
        bytes_recv = recv(sockfd, recv_buffer, SIZE, 0);
        if (bytes_recv <= 0)
        {
            break;
        }
        fprintf(fp, "%s", recv_buffer);
        bzero(recv_buffer, SIZE);
    }
    return;
}

int main()
{
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    printf("Client socket created successfully...");
    
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    printf("Client is connected...\n");

    recv_file(sockfd);

    printf("File data received successfully...\n");

    close(sockfd);

    return 0;
}                                