#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 1024


int main() {
    int sockfd; 
    struct sockaddr_in serverAddr{}, clientAddr{};
    char buffer[BUFFER_SIZE];

    // 1. Create UDP socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return 1;
    }

    // 2. Bind the socket to a local address and port
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY; // listen on all interfaces
    serverAddr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        return 1;
    }

    std::cout << "UDP Server Listening on port " << PORT << "...\n";

    // 3. Receive messages in a loop
    while (true) {
        socklen_t clientLen = sizeof(clientAddr);
        memset(buffer, 0, BUFFER_SIZE);

        ssize_t n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, 
                                (struct sockaddr*) &clientAddr, &clientLen);
        if (n < 0) {
            perror("recvfrom error");
            break;
        }

        std::cout << "Received from client: " << buffer << "\n";

        // 4. Send a response back to the client
        const char* response = "Hello from UDP Server";
        sendto(sockfd, response, strlen(response), 0,
                    (struct sockaddr*)&clientAddr, clientLen);
        std::cout << "Sent response to client.\n";
    }
    close(sockfd);
    return 0;
}