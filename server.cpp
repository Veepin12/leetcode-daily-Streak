// Server side C/C++ program for TCP Socket Communication
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Function to reverse a string
std::string reverseString(std::string str) {
    std::string reversed = str;
    std::reverse(reversed.begin(), reversed.end());
    return reversed;
}

// Function to add two numbers
int addTwoNumbers(int a, int b) {
    return a + b;
}

int main(int argc, char const* argv[]) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    socklen_t addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    const char* hello = "Hello from ";

 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

  
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        perror("setsockopt SO_REUSEADDR failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
#ifdef SO_REUSEPORT
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEPORT, &opt, sizeof(opt)) < 0) {
        perror("setsockopt SO_REUSEPORT failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
#endif

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

  
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

  
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    std::cout << "Server listening on port " << PORT << "..." << std::endl;

   
    if ((new_socket = accept(server_fd, (struct sockaddr*)&address, &addrlen)) < 0) {
        perror("Accept failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    std::cout << "Client connected successfully!" << std::endl;

    // Read data from client
    ssize_t valread = read(new_socket, buffer, BUFFER_SIZE - 1);
    if (valread > 0) {
        buffer[valread] = '\0';
        std::cout << "Received from client: " << buffer << std::endl;
        
        // Reverse the received string
        std::string receivedStr(buffer);
        std::string reversed = reverseString(receivedStr);
        std::cout << "Reversed string: " << reversed << std::endl;
    }
    
    // Example: Add two numbers
    int num1 = 10;
    int num2 = 20;
    int sum = addTwoNumbers(num1, num2);
    std::cout << "Adding " << num1 << " + " << num2 << " = " << sum << std::endl;
    
    // Send response to client
    send(new_socket, hello, strlen(hello), 0);
    std::cout << "Hello message sent to client." << std::endl;

   
    close(new_socket);
    close(server_fd);

    return 0;
}
