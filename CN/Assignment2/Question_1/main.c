// main.c

#include <stdio.h>
#include "protocol.h"

// Declare DLL functions
void WaitForEvent(EventType* event);
void GetData(char* dataBuffer);
void MakeFrame(const char* data, Frame* frame);
void SendFrame(const Frame* frame);
void ReceiveFrame(Frame* frame);
void ExtractData(const Frame* frame, char* dataBuffer);
void DeliverData(const char* data);

int main() {
    EventType event;
    char data[FRAME_SIZE];
    Frame frame;

    // Sender side
    WaitForEvent(&event);
    GetData(data);
    MakeFrame(data, &frame);
    SendFrame(&frame);

    // Receiver side
    ReceiveFrame(&frame);
    ExtractData(&frame, data);
    DeliverData(data);

    return 0;
}
