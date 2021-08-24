#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define PORT 8050

int main()
{
    int sockfd, conn;
    char servermessage[1024] = "Hi this is the server!";

    //Socket descriptor - Create a socket with a particular family, type and protocol 
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    //The SOCKADDR_IN structure specifies a transport address and port for the AF_INET address family.
    struct sockaddr_in server_addr, client_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY); //An IN_ADDR structure that contains an IPv4 transport address.

    //Bind the socket descriptor to the server address using the SOCKADDR_IN structure
    bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    //Listen for connections to the socket descriptor
    listen(sockfd, 5);

    printf("Server is running...\n");

    //Accept a connection from the client socket if and when data is sent
    conn = accept(sockfd, (struct sockaddr *)NULL, NULL);

    printf("Server is connected...\n");

    //Send data across the socket
    send(conn, servermessage, sizeof(servermessage), 0); 

    printf("Server message sent...\n");      
    
    //Close Socket
    close(sockfd);
    printf("Server closed...\n");

    return 0;
}

//To run
// gcc -o server tcp_server.c
// ./server