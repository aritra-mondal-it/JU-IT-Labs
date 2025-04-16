// receiver.c

#include <stdio.h>
#include <string.h>
#include "protocol.h"

#ifdef _WIN32
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif

// Simulate receiving a frame
DLL_EXPORT void ReceiveFrame(Frame* frame) {
    printf("[Receiver] Enter received frame data: ");
    fgets(frame->data, FRAME_SIZE, stdin);
    frame->data[strcspn(frame->data, "\n")] = '\0'; // Remove newline
}

// Extract data from the frame
DLL_EXPORT void ExtractData(const Frame* frame, char* dataBuffer) {
    strncpy(dataBuffer, frame->data, FRAME_SIZE);
}

// Deliver data to the application
DLL_EXPORT void DeliverData(const char* data) {
    printf("[Receiver] Data delivered: %s\n", data);
}
