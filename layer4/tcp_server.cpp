#include <iostream>
#include <cstring>
#include <unistd.h>         // OS API
#include <arpa/inet.h>      // BSD socket API 

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address; 
    char buffer[BUFFER_SIZE] = {0};
    const char *hello = "Hello from TCP server";

    // 1. Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        perror("Socket failed");
        return -1;
    }

    // 2. Bind socket to IP/Port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;   // Accept any incoming address
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        return -1;
    }

    // 3. Listen for connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        return -1;
    }

    std::cout << "TCP Server is waiting for a connection on port " << PORT << "...\n";

    // 4. Accept connection
    socklen_t addrlen = sizeof(address);
    new_socket = accept(server_fd, (struct sockaddr *)&address, &addrlen);
    if (new_socket < 0) {
        perror("Accept failed");
        return -1;
    }

    // 5. Read data from client
    read(new_socket, buffer, BUFFER_SIZE);
    std::cout << "Client says: " << buffer << std::endl;

    // 6. Send response to client
    send(new_socket, hello, strlen(hello), 0);
    std::cout << "Hello message sent to client\n";

    // 7. Close sockets
    close(new_socket);
    close(server_fd);

    return 0;
}