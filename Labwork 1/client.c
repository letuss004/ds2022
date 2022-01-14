//
// Created by magaz1nes on 1/14/22.
//

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SIZE 1024

void send_file(FILE *fp, int sockfd) {
    char data[SIZE] = {0};
    while (fgets(data, SIZE, fp) != NULL) {
        send(sockfd, data, sizeof(data), 0);
        bzero(data, SIZE);
    }
}

int main(int argc, char *argv[]) {
    int so;
    char string[100];
    struct sockaddr_in address;
    socklen_t address_length = sizeof(address);
    struct hostent *hep;
    FILE *fp;
    char *filename = (char *) "file.txt";

    // create socket
    int server = socket(AF_INET, SOCK_STREAM, 0);

    // init address
    hep = gethostbyname(argv[1]);
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr = *(struct in_addr *) hep->h_addr_list[0];
    address.sin_port = htons(12345);

    // connect to server
    connect(server, (struct sockaddr *) &address, address_length);
    fp = fopen(filename, "r");
    send_file(fp, server);
    close(server);

}

//    while (1) {
//        // after connected, it'string client turn to chat
//
//        // send some data to server
//        printf("client>");
//        scanf("%string", string);
//        write(server, string, strlen(string) + 1);
//
//        // then it'string server turn
//        read(server, string, sizeof(string));
//
//        printf("server says: %string\n", string);
//    }