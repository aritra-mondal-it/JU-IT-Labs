#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stopandwait.h"

// Declare functions
void sender_noiseless();
void receiver_noiseless(Frame frame);
void sender_noisy(float loss_prob, float corrupt_prob);
int receiver_noisy(Frame frame, float loss_prob, float corrupt_prob);

int main() {
    int choice;
    srand(time(NULL)); // Seed random

    printf("STOP-AND-WAIT PROTOCOL\n");
    printf("1. Noiseless Channel\n");
    printf("2. Noisy Channel\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar(); // clear newline

    if (choice == 1) {
        sender_noiseless();
    } else if (choice == 2) {
        float loss = 0.2f;     // 20% chance of frame loss
        float corrupt = 0.1f;  // 10% chance of frame corruption
        sender_noisy(loss, corrupt);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
