// protocol.h

#ifndef PROTOCOL_H
#define PROTOCOL_H

#define FRAME_SIZE 1024

typedef struct {
    char data[FRAME_SIZE];
} Frame;

typedef enum {
    FRAME_ARRIVAL
} EventType;

#endif // PROTOCOL_H
