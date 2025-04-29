#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_BUFFER 7

typedef struct {
    int seq;
    char data;
} Frame;

typedef struct {
    int ack_no;
    int fbit;
} ACK;

int buffer_count = 0;

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    Frame frame;
    ACK ack;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 3);

    printf("Receiver waiting for connection...\n");
    new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
    printf("Connection established with sender.\n");

    while (1) {
        int bytes = recv(new_socket, &frame, sizeof(Frame), 0);
        if (bytes <= 0) break;

        printf("Received Frame: SEQ=%d DATA=%c\n", frame.seq, frame.data);

        // Process and update buffer
        buffer_count++;
        if (buffer_count >= MAX_BUFFER) buffer_count = 0;

        ack.ack_no = frame.seq;
        ack.fbit = (buffer_count <= 1) ? 0 : 1;  // simulate buffer full/ample

        send(new_socket, &ack, sizeof(ACK), 0);
    }

    close(new_socket);
    close(server_fd);
    return 0;
}
