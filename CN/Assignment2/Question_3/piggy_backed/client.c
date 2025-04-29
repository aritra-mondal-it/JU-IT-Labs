// File: client.c
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
int sockfd;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *send_frames(void *arg) {
    char msg[1024];

    while (next_seq < TOTAL_FRAMES) {
        pthread_mutex_lock(&lock);
        sprintf(msg, "SEQ:%d:ACK:%d:Msg_from_Client_%d", next_seq, last_ack_received, next_seq);
        send(sockfd, msg, strlen(msg), 0);
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
        int bytes = recv(sockfd, buffer, sizeof(buffer), 0);
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
            printf("Client: Received expected seq %d\n", seq);
            last_ack_received = seq;
            expected_seq++;
        } else {
            printf("Client: Unexpected seq %d (Expected: %d)\n", seq, expected_seq);
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
    printf("Connected to server...\n");

    pthread_create(&sender, NULL, send_frames, NULL);
    pthread_create(&receiver, NULL, receive_frames, NULL);

    pthread_join(sender, NULL);
    pthread_join(receiver, NULL);

    close(sockfd);
    return 0;
}
