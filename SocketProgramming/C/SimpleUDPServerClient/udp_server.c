// Imports
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
    struct sockaddr_in server_addr, client_addr;

    //Create a UDP Socket with a specific family type and protocol
    if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("Socket Creation Failed");
        exit(EXIT_FAILURE);
    }
    printf("Server is running...\n");

    //Set the memory taken by the variable to 0
    memset(&server_addr, 0, sizeof(server_addr));
    memset(&client_addr, 0, sizeof(client_addr));
    // bzero(&server_addr, sizeof(server_addr));
    // bzero(&client_addr, sizeof(client_addr));

    //Server Information
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    // Bind Socket descriptor to server address
    if(bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is connected and waiting...\n");

    // Receive Message from client
    int len = sizeof(client_addr);
    int number_of_bytes_read;
    number_of_bytes_read = recvfrom(sockfd, client_msg, 10000, MSG_WAITALL, (struct sockaddr *)&client_addr, &len);
    client_msg[number_of_bytes_read] = '\0';
    printf("Client : %s\n", client_msg);

    // Send Message to client
    printf("\nEnter message here: ");
    fgets(server_msg, 10000, stdin);
    sendto(sockfd, server_msg, strlen(server_msg)+1, MSG_CONFIRM, (const struct sockaddr *)&client_addr, sizeof(client_addr));

    //Close Socket
    close(sockfd);
    printf("Server is offline...\n");
    return 0;
}