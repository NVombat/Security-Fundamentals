#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define PORT 8000

int main()
{
    int server_sock, conn;
    char servermessage[1024] = "Hi this is the server!";

    server_sock = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(server_sock, (struct sockaddr *) &addr, sizeof(addr));
    listen(server_sock, 5);

    printf("Server is running...\n");

    conn = accept(server_sock, NULL, NULL);

    printf("Server is connected...\n");

    send(conn, servermessage, sizeof(servermessage), 0); 

    printf("Server message sent...\n");      
    
    close(server_sock);
    printf("Server closed...\n");

    return 0;
}