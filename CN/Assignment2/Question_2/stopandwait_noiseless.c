#include <stdio.h>
#include <string.h>
#include "stopandwait.h"

void receiver_noiseless(Frame frame);

void sender_noiseless() {
    Frame frame;
    char buffer[FRAME_SIZE];

    printf("[Sender] Enter message: ");
    fgets(buffer, FRAME_SIZE, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';

    frame.seq = 0;
    strcpy(frame.data, buffer);

    printf("[Sender] Sending frame with seq %d: %s\n", frame.seq, frame.data);

    // Simulate transmission to receiver
    receiver_noiseless(frame);
}

void receiver_noiseless(Frame frame) {
    printf("[Receiver] Frame received with seq %d: %s\n", frame.seq, frame.data);
    printf("[Receiver] Sending ACK\n");
    // Normally ACK would be sent, but no retransmission needed in noiseless
}
