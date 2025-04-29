#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_SEQ 7

typedef struct {
    int seq;
    char data;
} Frame;

typedef struct {
    int ack_no;
    int fbit;
} ACK;

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    Frame frame;
    ACK ack;
    char data[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int base = 0, next_seq = 0;
    int window_size = MAX_SEQ;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);
    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    while (base < sizeof(data)) {
        while (next_seq < base + window_size && next_seq < sizeof(data)) {
            frame.seq = next_seq % (MAX_SEQ + 1);
            frame.data = data[next_seq];

            send(sock, &frame, sizeof(Frame), 0);
            printf("Sent Frame: SEQ=%d DATA=%c\n", frame.seq, frame.data);

            recv(sock, &ack, sizeof(ACK), 0);
            printf("Received ACK: %d F-bit=%d\n", ack.ack_no, ack.fbit);

            // Adjust window size based on F-bit
            window_size = (ack.fbit == 0) ? 1 : MAX_SEQ;
            base++;
            next_seq++;
            usleep(500000);  // simulate delay
        }
    }

    close(sock);
    return 0;
}
