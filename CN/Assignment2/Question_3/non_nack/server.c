#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    char buffer[1024] = {0};
    int expected = 0;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);
    address.sin_addr.s_addr = INADDR_ANY;

    bind(server_fd, (struct sockaddr*)&address, sizeof(address));
    listen(server_fd, 3);
    new_socket = accept(server_fd, NULL, NULL);

    while (1) {
        int bytes = recv(new_socket, buffer, sizeof(buffer), 0);
        if (bytes <= 0) break;

        int seq = atoi(buffer);
        printf("Received frame: %d\n", seq);

        if (seq == expected) {
            printf("Accepted frame %d\n", seq);
            char ack[10];
            sprintf(ack, "%d", seq);
            send(new_socket, ack, sizeof(ack), 0);
            expected++;
        } else {
            printf("Out of order. Discarded.\n");
        }
    }

    close(new_socket);
    close(server_fd);
    return 0;
}
