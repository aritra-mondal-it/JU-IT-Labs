// stopandwait.h

#ifndef STOPANDWAIT_H
#define STOPANDWAIT_H

#define FRAME_SIZE 1024

typedef struct {
    int seq;             // Sequence number
    char data[FRAME_SIZE]; // Payload
} Frame;

typedef enum {
    ACK,
    NAK
} AckType;

#endif
