#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8000
#define BUFFER_SIZE 1024

int sock;
char buffer[BUFFER_SIZE];

// Function to receive messages from the server
void* receive_messages(void* arg) {
    while (1) {
        memset(buffer, 0, sizeof(buffer)); // Clear the buffer
        int valread = read(sock, buffer, BUFFER_SIZE);
        if (valread > 0) {
            buffer[valread] = '\0';  // Null-terminate the received message
            printf("Server: %s\n", buffer);
            if (strcmp(buffer, "bye") == 0) {
                printf("Server terminated the connection.\n");
                close(sock);
                exit(0);
            }
        }
    }
}

int main() {
    struct sockaddr_in serv_addr;
    char server_ip[BUFFER_SIZE];  // To store the server IP entered by the user

    // Prompt the user to enter the server IP address
    printf("Enter server IP address: ");
    fgets(server_ip, BUFFER_SIZE, stdin);
    server_ip[strcspn(server_ip, "\n")] = 0; // Remove the newline character from input

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert the IP address from text to binary form
    if (inet_pton(AF_INET, server_ip, &serv_addr.sin_addr) <= 0) {
        perror("Invalid address / Address not supported");
        return -1;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection Failed");
        return -1;
    }

    printf("Connected to server at %s!\n", server_ip);

    // Create a thread to handle receiving messages from the server
    pthread_t recv_thread;
    pthread_create(&recv_thread, NULL, receive_messages, NULL);

    while (1) {
        printf("Enter message: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = 0;  // Remove newline character from the input

        // If the client types "bye", close the connection
        if (strcmp(buffer, "bye") == 0) {
            send(sock, buffer, strlen(buffer), 0);
            printf("You terminated the connection.\n");
            close(sock);
            break;
        }

        // Send message to server
        send(sock, buffer, strlen(buffer), 0);
    }

    // Wait for the receive thread to finish
    pthread_join(recv_thread, NULL);

    return 0;
}
