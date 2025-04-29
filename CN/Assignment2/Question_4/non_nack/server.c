// File: server.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8091
#define TOTAL_FRAMES 8

int received[TOTAL_FRAMES];

int main() {
    int server_fd, client_fd;
    struct sockaddr_in addr;
    char buffer[1024];
    memset(received, 0, sizeof(received));

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_fd, (struct sockaddr*)&addr, sizeof(addr));
    listen(server_fd, 3);

    client_fd = accept(server_fd, NULL, NULL);
    printf("Client connected...\n");

    int expected_seq = 0;

    while (1) {
        int bytes = recv(client_fd, buffer, sizeof(buffer), 0);
        if (bytes <= 0) break;
        buffer[bytes] = '\0';

        if (strncmp(buffer, "FRAME:", 6) == 0) {
            int seq = atoi(buffer + 6);
            printf("Received frame: %d\n", seq);

            if (seq == expected_seq) {
                received[seq] = 1;
                expected_seq++;

                char ack[20];
                sprintf(ack, "ACK:%d", seq);
                send(client_fd, ack, sizeof(ack), 0);
            } else if (seq > expected_seq) {
                printf("Out-of-order frame received. Expected: %d\n", expected_seq);

                char nack[20];
                sprintf(nack, "NACK:%d", expected_seq);
                send(client_fd, nack, sizeof(nack), 0);
            } else {
                // Duplicate or already ACKed
                char ack[20];
                sprintf(ack, "ACK:%d", seq);
                send(client_fd, ack, sizeof(ack), 0);
            }
        }
    }

    close(client_fd);
    close(server_fd);
    return 0;
}
