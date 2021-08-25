#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8100

int main()
{
    int sockfd, conn;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    char server_msg[1024];
    char client_msg[1024];

    struct sockaddr_in server_addr, client_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    printf("Server is running...\n");

    bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(sockfd, 5);

    printf("Server is listening...\n");

    conn = accept(sockfd, (struct sockaddr *)NULL, NULL);

    printf("Server is connected...\n");

    while(1)
    {
        printf("\nEnter message here: ");
        scanf("%s", server_msg);
        send(conn, server_msg, sizeof(server_msg), 0);
        recv(conn, &client_msg, sizeof(client_msg), 0);
        printf("\nClient Message: %s\n", client_msg);
    }

    close(sockfd);
    printf("Server is offline...\n");
    return 0;
}