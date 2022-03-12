#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

#define DESTPORT 3500

int main()
{

    struct sockaddr_in dest_addr;
    
    int sockfd = socket(AF_INET,SOCK_STREAM,0);

    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(DESTPORT);
    dest_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    dest_addr.sin_zero[8]='\0';

    connect(sockfd,(struct sockaddr*)&dest_addr, sizeof(struct sockaddr));

    char msg[100];
    printf("Enter you message: ");
    gets(&msg); 
    
    int w = write(sockfd, msg, strlen(msg));
    
    close(sockfd);
    printf("Client Dying.....\n"); 

    return 0;
}