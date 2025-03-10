// Raw Socket (ICMP Example)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>

#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in dest_addr;
    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    dest_addr.sin_family = AF_INET;
    inet_pton(AF_INET, "8.8.8.8", &dest_addr.sin_addr);

    memset(buffer, 0, BUFFER_SIZE);
    struct icmphdr *icmp = (struct icmphdr *)buffer;
    icmp->type = ICMP_ECHO;
    icmp->checksum = 0;

    sendto(sockfd, buffer, sizeof(struct icmphdr), 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr));
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("ICMP Reply received\n");
    close(sockfd);
    return 0;
}