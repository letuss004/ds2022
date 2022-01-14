//
// Created by magaz1nes on 1/14/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define SIZE 1024

void foo(int cli, char *s);

void write_file(int sockfd) {
    int n;
    FILE *fp;
    char *filename = "file2.txt";
    char buffer[SIZE];

    fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("[-]Error in creating file.");
        exit(1);
    }
    while (1) {
        n = recv(sockfd, buffer, SIZE, 0);
        if (n <= 0) {
            break;
            return;
        }
        fprintf(fp, "%s", buffer);
        bzero(buffer, SIZE);
    }
    return;

}

int main() {
    int ss, cli, pid;
    struct sockaddr_in ad;
    char s[100];
    socklen_t ad_length = sizeof(ad);

    // create the socket
    ss = socket(AF_INET, SOCK_STREAM, 0);
    // bind the socket to port 12345
    memset(&ad, 0, sizeof(ad));
    ad.sin_family = AF_INET;
    ad.sin_addr.s_addr = INADDR_ANY;
    ad.sin_port = htons(12345);
    bind(ss, (struct sockaddr *) &ad, ad_length);

    // then listen
    listen(ss, 0);

    while (1) {
        // an incoming connection
        cli = accept(ss, (struct sockaddr *) &ad, &ad_length);

        pid = fork();
        if (pid == 0) {
            // I'm the son, I'll serve this client
            printf("client connected\n");
//            while (1) {
//                foo(cli, s);
//            }
            write_file(cli);
            return 0;
        } else {
            // I'm the father, continue the loop to accept more clients
            continue;
        }
    }
    // disconnect
    close(cli);
}

void foo(int cli, char *s) {// it's client turn to chat, I wait and read message from client
    read(cli, s, sizeof(s));
    printf("client says: %s\n", s);

    // now it's my (server) turn
    printf("server>", s);
    scanf("%s", s);
    write(cli, s, strlen(s) + 1);
}

