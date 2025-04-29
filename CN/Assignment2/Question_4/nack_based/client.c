#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8090
#define WINDOW_SIZE 4
#define TOTAL_FRAMES 8

int acked[TOTAL_FRAMES];

void send_frame(int sockfd, int seq) {
    char msg[10];
    sprintf(msg, "%d", seq);
    send(sockfd, msg, sizeof(msg), 0);
    printf("Sent frame: %d\n", seq);
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char ack[10];
    memset(acked, 0, sizeof(acked));

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));

    int base = 0;
    while (base < TOTAL_FRAMES) {
        for (int i = 0; i < WINDOW_SIZE && base + i < TOTAL_FRAMES; i++) {
            if (!acked[base + i]) {
                send_frame(sockfd, base + i);
            }
        }

        recv(sockfd, ack, sizeof(ack), 0);
        int ack_num = atoi(ack);
        printf("Received ACK: %d\n", ack_num);
        acked[ack_num] = 1;

        while (acked[base]) base++;
    }

    close(sockfd);
    return 0;
}
