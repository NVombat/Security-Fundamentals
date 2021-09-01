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

void send_file(int sockfd, FILE *fp)
{
    char file_data[SIZE];
    while(fgets(file_data, SIZE, fp) != NULL)
    {
        if(send(sockfd, file_data, sizeof(file_data), 0) == -1)
        {
            perror("Error in sending file...");
            exit(1);
        }
        bzero(file_data, SIZE);
    }
    return;
}

int main()
{
    int sockfd, conn;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;

    FILE *fhand;
    char *filename = "sample.txt";
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        perror("Error in socket...");
        exit(1);
    }

    printf("Server socket created successfully...\n");
    
    bzero(&server_addr, sizeof(server_addr));
    bzero(&client_addr, sizeof(client_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    listen(sockfd, 5);

    printf("Server is listening...\n");

    conn = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);

    printf("Server is connected...\n");

    fhand = fopen(filename, "r");
    if (fhand == NULL) 
    {
        perror("Error in reading file...");
        exit(1);
    }
    send_file(conn, fhand);

    printf("File data sent successfully...\n");

    close(sockfd);

    return 0;
}