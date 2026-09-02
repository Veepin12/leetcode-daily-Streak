// TCP Socket Communication in C++ (Combined Server and Client)
// Usage:
//   Compile: g++ -std=c++17 socket.cpp -o socket
//   Run Server: ./socket server
//   Run Client: ./socket client

#include <iostream>
#include <cstring>
#include <algorithm>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
using namespace std;

#define PORT 8080
#define BUFFER_SIZE 1024


string reverseString(std::string str) {
    string reversed = str;
    reverse(reversed.begin(), reversed.end());
    return reversed;
}


int addTwoNumbers(int a, int b) {
    return a + b;
}

int run_server() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    socklen_t addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    const char* hello = "Hello from server";

    cout << "\n=== Starting TCP Server ===" <<endl;

  
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return -1;
    }

    
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        perror("setsockopt SO_REUSEADDR failed");
        close(server_fd);
        return -1;
    }
#ifdef SO_REUSEPORT
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEPORT, &opt, sizeof(opt)) < 0) {
        perror("setsockopt SO_REUSEPORT failed");
        close(server_fd);
        return -1;
    }
#endif

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // 3. Bind socket to port
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_fd);
        return -1;
    }

    // 4. Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        close(server_fd);
        return -1;
    }

    std::cout << "Server listening on port " << PORT << ". Waiting for client..." << std::endl;

    // 5. Accept client connection
    if ((new_socket = accept(server_fd, (struct sockaddr*)&address, &addrlen)) < 0) {
        perror("Accept failed");
        close(server_fd);
        return -1;
    }

    std::cout << "Client connected successfully!" << std::endl;

    // 6. Read message from client
    ssize_t valread = read(new_socket, buffer, BUFFER_SIZE - 1);
    if (valread > 0) {
        buffer[valread] = '\0';
        std::cout << "Received from client: " << buffer << std::endl;
        
        // Reverse the received string
        std::string receivedStr(buffer);
        std::string reversed = reverseString(receivedStr);
        std::cout << "Reversed string: " << reversed << std::endl;
    }
    
    // Add two numbers example
    int num1 = 15;
    int num2 = 25;
    int sum = addTwoNumbers(num1, num2);
    std::cout << "Adding " << num1 << " + " << num2 << " = " << sum << std::endl;

    // 7. Send response to client
    send(new_socket, hello, strlen(hello), 0);
    std::cout << "Hello message sent to client." << std::endl;

    // 8. Close sockets
    close(new_socket);
    close(server_fd);
    std::cout << "Server connection closed.\n" << std::endl;

    return 0;
}

int run_client() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    const char* hello = "Hello from client";
    char buffer[BUFFER_SIZE] = {0};

    std::cout << "\n=== Starting TCP Client ===" << std::endl;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

   
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        std::cerr << "Invalid address / Address not supported" << std::endl;
        close(sock);
        return -1;
    }


    std::cout << "Connecting to server on 127.0.0.1:" << PORT << "..." << std::endl;
    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection Failed");
        close(sock);
        return -1;
    }

    std::cout << "Connected to server!" << std::endl;
    
    // Test reverse string functionality on client side
    std::string testStr = "Hello";
    std::string reversedTest = reverseString(testStr);
    std::cout << "Original: " << testStr << ", Reversed: " << reversedTest << std::endl;
    
    // Test add two numbers on client side
    int a = 5;
    int b = 10;
    int result = addTwoNumbers(a, b);
    std::cout << "Adding " << a << " + " << b << " = " << result << std::endl;

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
    std::cout << "Client connection closed.\n" << std::endl;

    return 0;
}

int main(int argc, char const* argv[]) {
    if (argc > 1) {
        if (strcmp(argv[1], "server") == 0 || strcmp(argv[1], "1") == 0) {
            return run_server();
        } else if (strcmp(argv[1], "client") == 0 || strcmp(argv[1], "2") == 0) {
            return run_client();
        } else {
            std::cerr << "Usage: " << argv[0] << " [server|client]" << std::endl;
            return 1;
        }
    }

    std::cout << "Select mode to run:\n";
    std::cout << "1. Run Server\n";
    std::cout << "2. Run Client\n";
    std::cout << "Enter choice (1 or 2): ";

    int choice = 0;
    if (std::cin >> choice) {
        if (choice == 1) {
            return run_server();
        } else if (choice == 2) {
            return run_client();
        }
    }

    std::cerr << "Invalid choice." << std::endl;
    return 1;
}