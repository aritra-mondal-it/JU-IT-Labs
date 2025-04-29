// File: server.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>

#define PORT 8082
#define MAX_SEQ 3
#define TOTAL_FRAMES 5

int next_seq = 0, base = 0, last_ack_received = -1;
int expected_seq = 0;
int client_sock;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *send_frames(void *arg) {
    char msg[1024];

    while (next_seq < TOTAL_FRAMES) {
        pthread_mutex_lock(&lock);
        sprintf(msg, "SEQ:%d:ACK:%d:Msg_from_Server_%d", next_seq, last_ack_received, next_seq);
        send(client_sock, msg, strlen(msg), 0);
        printf("Sent: %s\n", msg);
        pthread_mutex_unlock(&lock);
        sleep(2);
        next_seq++;
    }
    return NULL;
}

void *receive_frames(void *arg) {
    char buffer[1024];

    while (1) {
        int bytes = recv(client_sock, buffer, sizeof(buffer), 0);
        if (bytes <= 0) break;
        buffer[bytes] = '\0';

        int seq, ack;
        sscanf(buffer, "SEQ:%d:ACK:%d:", &seq, &ack);

        pthread_mutex_lock(&lock);
        printf("Received: %s\n", buffer);

        if (ack >= base) {
            base = ack + 1;
            printf("ACK received up to: %d\n", ack);
        }

        if (seq == expected_seq) {
            printf("Server: Received expected seq %d\n", seq);
            last_ack_received = seq;
            expected_seq++;
        } else {
            printf("Server: Unexpected seq %d (Expected: %d)\n", seq, expected_seq);
        }

        pthread_mutex_unlock(&lock);
    }

    return NULL;
}

int main() {
    int server_fd;
    struct sockaddr_in address;
    pthread_t sender, receiver;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);
    address.sin_addr.s_addr = INADDR_ANY;

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 3);
    printf("Server listening on port %d...\n", PORT);

    client_sock = accept(server_fd, NULL, NULL);
    printf("Client connected.\n");

    pthread_create(&sender, NULL, send_frames, NULL);
    pthread_create(&receiver, NULL, receive_frames, NULL);

    pthread_join(sender, NULL);
    pthread_join(receiver, NULL);

    close(client_sock);
    close(server_fd);
    return 0;
}
