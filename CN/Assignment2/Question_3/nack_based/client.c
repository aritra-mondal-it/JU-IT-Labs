// File: client.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8081
#define MAX_SEQ 3
#define WINDOW_SIZE (MAX_SEQ + 1)
#define TOTAL_FRAMES 10

void send_frame(int sockfd, int seq) {
    char frame[10];
    sprintf(frame, "%d", seq);
    send(sockfd, frame, sizeof(frame), 0);
    printf("Sent frame: %d\n", seq);
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[1024];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));

    int base = 0, next_seq = 0;

    while (base < TOTAL_FRAMES) {
        while (next_seq < base + WINDOW_SIZE && next_seq < TOTAL_FRAMES) {
            send_frame(sockfd, next_seq);
            next_seq++;
        }

        recv(sockfd, buffer, sizeof(buffer), 0);

        if (strncmp(buffer, "ACK:", 4) == 0) {
            int ack_num = atoi(buffer + 4);
            printf("Received ACK for frame %d\n", ack_num);
            if (ack_num >= base) base = ack_num + 1;
        } else if (strncmp(buffer, "NACK:", 5) == 0) {
            int nack_num = atoi(buffer + 5);
            printf("Received NACK for frame %d. Resending from %d\n", nack_num, nack_num);
            next_seq = nack_num;
        }
    }

    close(sockfd);
    return 0;
}
