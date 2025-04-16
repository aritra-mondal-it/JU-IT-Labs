// sender.c

#include <stdio.h>
#include <string.h>
#include "protocol.h"

#ifdef _WIN32
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif

// Simulate waiting for the ability to send
DLL_EXPORT void WaitForEvent(EventType* event) {
    *event = FRAME_ARRIVAL; // Always ready in simplest protocol
}

// Get data from the application
DLL_EXPORT void GetData(char* dataBuffer) {
    printf("[Sender] Enter data to send: ");
    fgets(dataBuffer, FRAME_SIZE, stdin);
    dataBuffer[strcspn(dataBuffer, "\n")] = '\0'; // Remove newline
}

// Package data into a frame
DLL_EXPORT void MakeFrame(const char* data, Frame* frame) {
    strncpy(frame->data, data, FRAME_SIZE);
}

// Send the frame (simulation)
DLL_EXPORT void SendFrame(const Frame* frame) {
    printf("[Sender] Frame sent: %s\n", frame->data);
    // Normally, would send frame over the network
}
