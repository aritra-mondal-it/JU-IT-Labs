#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "stopandwait.h"

int receiver_noisy(Frame frame, float loss_prob, float corrupt_prob);

int simulate_noise(float loss_prob, float corrupt_prob) {
    float r = (float)rand() / RAND_MAX;
    if (r < loss_prob) return 1;         // Simulate lost frame
    else if (r < loss_prob + corrupt_prob) return 2; // Simulate corrupted frame
    return 0;                             // Frame okay
}

void sender_noisy(float loss_prob, float corrupt_prob) {
    Frame frame;
    int ack_received = 0;
    char buffer[FRAME_SIZE];
    int attempts = 0;

    printf("[Sender] Enter message: ");
    fgets(buffer, FRAME_SIZE, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';

    frame.seq = 0;
    strcpy(frame.data, buffer);

    while (!ack_received) {
        printf("\n[Sender] Sending frame: %s\n", frame.data);
        int result = receiver_noisy(frame, loss_prob, corrupt_prob);

        if (result == ACK) {
            printf("[Sender] ACK received. Transmission successful.\n");
            ack_received = 1;
        } else {
            printf("[Sender] No ACK or NAK received. Retrying...\n");
            attempts++;
        }

        if (attempts > 5) {
            printf("[Sender] Transmission failed after multiple attempts.\n");
            break;
        }
    }
}

int receiver_noisy(Frame frame, float loss_prob, float corrupt_prob) {
    int status = simulate_noise(loss_prob, corrupt_prob);

    if (status == 1) {
        printf("[Receiver] Frame lost in transit.\n");
        return NAK;
    } else if (status == 2) {
        printf("[Receiver] Frame corrupted.\n");
        return NAK;
    } else {
        printf("[Receiver] Frame received: %s\n", frame.data);
        printf("[Receiver] Sending ACK\n");
        return ACK;
    }
}
