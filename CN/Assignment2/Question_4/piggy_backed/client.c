// File: client.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>

#define PORT 8092
#define TOTAL_FRAMES 5

int sockfd;
int send_base = 0, expected_recv = 0;
int acked[TOTAL_FRAMES] = {0};
int received[TOTAL_FRAMES] = {0};
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *send_frames(void *arg) {
    for (int i = 0; i < TOTAL_FRAMES; i++) {
        pthread_mutex_lock(&lock);
        char msg[128];
        sprintf(msg, "SEQ:%d:ACK:%d:ClientMsg%d", i, expected_recv - 1, i);
        send(sockfd, msg, strlen(msg), 0);
        printf("Sent: %s\n", msg);
        pthread_mutex_unlock(&lock);
        sleep(1);
    }
    return NULL;
}

void *receive_frames(void *arg) {
    char buffer[128];
    while (1) {
        int bytes = recv(sockfd, buffer, sizeof(buffer), 0);
        if (bytes <= 0) break;
        buffer[bytes] = '\0';

        int seq, ack;
        sscanf(buffer, "SEQ:%d:ACK:%d:", &seq, &ack);
        pthread_mutex_lock(&lock);

        if (ack >= 0 && ack < TOTAL_FRAMES) {
            printf("Client received ACK for %d\n", ack);
            acked[ack] = 1;
        }

        if (seq >= 0 && seq < TOTAL_FRAMES && !received[seq]) {
            printf("Client received frame %d: %s\n", seq, buffer);
            received[seq] = 1;
            expected_recv++;
        }

        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    struct sockaddr_in server_addr;
    pthread_t sender, receiver;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    printf("Client connected to server...\n");

    pthread_create(&sender, NULL, send_frames, NULL);
    pthread_create(&receiver, NULL, receive_frames, NULL);

    pthread_join(sender, NULL);
    pthread_join(receiver, NULL);

    close(sockfd);
    return 0;
}
