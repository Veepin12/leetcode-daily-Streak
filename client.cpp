// Client side C/C++ program for TCP Socket Communication
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char const* argv[]) {
    int sock = 0;
    struct sockaddr_in serv_addr;
    const char* hello = "Hello from client";
    char buffer[BUFFER_SIZE] = {0};

    // 1. Create socket file descriptor
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // 2. Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        std::cerr << "Invalid address / Address not supported" << std::endl;
        close(sock);
        return -1;
    }

    // 3. Connect to server
    std::cout << "Connecting to server on 127.0.0.1:" << PORT << "..." << std::endl;
    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection Failed");
        close(sock);
        return -1;
    }

    std::cout << "Connected to server!" << std::endl;

    // 4. Send message to server
    send(sock, hello, strlen(hello), 0);
    std::cout << "Hello message sent to server." << std::endl;

    // 5. Read response from server
    ssize_t valread = read(sock, buffer, BUFFER_SIZE - 1);
    if (valread > 0) {
        buffer[valread] = '\0';
        std::cout << "Received from server: " << buffer << std::endl;
    }

    // 6. Close socket connection
    close(sock);

    return 0;
}
