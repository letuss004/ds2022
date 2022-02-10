//
// Created by magaz1nes on 2/9/22.
//

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>


#define IP_ADDRESS "127.0.0.1"
#define PORT 12345
#define BUFF_SIZE 100


int receive_file(char *buf, int s) {
    int i;
    char ch;
    for (i = 0; i < s; i++) {
        ch = buf[i];
        if (ch == -1) return 1; // file emty
        else printf("%c", ch);
    }
    return 0;
}

int main() {
    int sockfd;
    struct sockaddr_in addr_con;
    socklen_t addrlen = sizeof(addr_con);
    char buf[BUFF_SIZE];

    addr_con.sin_family = AF_INET;
    addr_con.sin_port = htons(PORT);
    addr_con.sin_addr.s_addr = inet_addr(IP_ADDRESS);

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    sendto(sockfd, "file.txt", BUFF_SIZE, 0, (struct sockaddr *) &addr_con, addrlen);
    while (1) {
        recvfrom(sockfd, buf, BUFF_SIZE, 0, (struct sockaddr *) &addr_con, &addrlen);
        if (receive_file(buf, BUFF_SIZE)) { break; }
    }
    return 0;
}
