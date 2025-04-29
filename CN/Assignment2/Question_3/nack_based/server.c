// File: server.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8081

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    char buffer[1024] = {0};
    int expected_seq = 0;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);
    address.sin_addr.s_addr = INADDR_ANY;

    bind(server_fd, (struct sockaddr*)&address, sizeof(address));
    listen(server_fd, 3);
    printf("Waiting for connection on port %d...\n", PORT);
    new_socket = accept(server_fd, NULL, NULL);
    printf("Client connected.\n");

    while (1) {
        int bytes = recv(new_socket, buffer, sizeof(buffer), 0);
        if (bytes <= 0) break;

        int seq = atoi(buffer);
        printf("Received frame: %d\n", seq);

        if (seq == expected_seq) {
            printf("Accepted frame %d\n", seq);
            char ack_msg[10];
            sprintf(ack_msg, "ACK:%d", seq);
            send(new_socket, ack_msg, sizeof(ack_msg), 0);
            expected_seq++;
        } else {
            printf("Frame out of order. Expected: %d. Sending NACK.\n", expected_seq);
            char nack_msg[10];
            sprintf(nack_msg, "NACK:%d", expected_seq);
            send(new_socket, nack_msg, sizeof(nack_msg), 0);
        }
    }

    close(new_socket);
    close(server_fd);
    return 0;
}
