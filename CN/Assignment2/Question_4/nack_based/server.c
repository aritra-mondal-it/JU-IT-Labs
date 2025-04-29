#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8090
#define TOTAL_FRAMES 8

int received[TOTAL_FRAMES];

int main() {
    int server_fd, client_fd;
    struct sockaddr_in addr;
    char buffer[10];
    memset(received, 0, sizeof(received));

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = INADDR_ANY;
    bind(server_fd, (struct sockaddr*)&addr, sizeof(addr));
    listen(server_fd, 3);

    client_fd = accept(server_fd, NULL, NULL);
    while (1) {
        int bytes = recv(client_fd, buffer, sizeof(buffer), 0);
        if (bytes <= 0) break;

        int seq = atoi(buffer);
        printf("Received frame: %d\n", seq);
        if (!received[seq]) {
            received[seq] = 1;
            char ack[10];
            sprintf(ack, "%d", seq);
            send(client_fd, ack, sizeof(ack), 0);
        }
    }

    close(client_fd);
    close(server_fd);
    return 0;
}
