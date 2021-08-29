//Imports
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8150

int main()
{
    int sockfd;
    char server_msg[10000], client_msg[10000];
    struct sockaddr_in server_addr;

    //Create a UDP Socket with a specific family type and protocol
    if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("Socket Creation Failed");
        exit(EXIT_FAILURE);
    }

    printf("Client is running...\n");

    //Set the memory taken by the variable to 0
    memset(&server_addr, 0, sizeof(server_addr));
    // bzero(&server_addr, sizeof(server_addr));

    //Server Information
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    printf("Client is Connected...\n");
    
    // Send Message to server
    int len = sizeof(server_addr);
    printf("\nEnter message here: ");
    fgets(client_msg, 10000, stdin);
    sendto(sockfd, client_msg, strlen(client_msg)+1, MSG_CONFIRM, (const struct sockaddr *)&server_addr, sizeof(server_addr));

    // Receive Message from server
    int number_of_bytes_read;
    number_of_bytes_read = recvfrom(sockfd, server_msg, 10000, MSG_WAITALL, (struct sockaddr *)&server_addr, &len);
    server_msg[number_of_bytes_read] = '\0';
    printf("Server : %s\n", server_msg);
    
    // Close Socket
    close(sockfd);
    printf("Client is Offline...\n");
    return 0;
}