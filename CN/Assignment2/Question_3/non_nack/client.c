#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_SEQ 3
#define WINDOW_SIZE (MAX_SEQ + 1)
#define PORT 8080

void send_frame(int sockfd, int seq) {
    char frame[10];
    sprintf(frame, "%d", seq);
    send(sockfd, frame, sizeof(frame), 0);
    printf("Sent frame: %d\n", seq);
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char ack[10];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));

    int base = 0, next_seq = 0;
    while (base < 10) {
        while ((next_seq < base + WINDOW_SIZE) && (next_seq < 10)) {
            send_frame(sockfd, next_seq);
            next_seq++;
        }

        recv(sockfd, ack, sizeof(ack), 0);
        printf("Received ACK: %s\n", ack);
        base = atoi(ack) + 1;
    }

    close(sockfd);
    return 0;
}
