#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define PORT 8050

int main()
{
    int sockfd;
    //Socket descriptor - Create a socket with a particular family, type and protocol 
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    //The SOCKADDR_IN structure specifies a transport address and port for the AF_INET address family.
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY); //An IN_ADDR structure that contains an IPv4 transport address.

    //Connect to the server via the socket
    connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));

    printf("Client is connected...\n");

    //Receive the message from the server and display it
    char serverresponse[1024];
    recv(sockfd, &serverresponse, sizeof(serverresponse), 0);
    printf("Server message: %s\n", serverresponse);

    //Close Socket
    close(sockfd);
    printf("Client is closed...\n");

    return 0;
}

//To run
// gcc -o client tcp_client.c
// ./client