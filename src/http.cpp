#include "../include/http.hpp"

std::string Http::make_response_html(std::string& message) {
    std::ostringstream response;
    response << "HTTP/1.1 200 OK\r\n"
             << "Content-Type: text/html\r\n" 
             << "Content-Length: " << message.length() << "\r\n" 
             <<  "\r\n"
             << message;
    return response.str();
}

std::string Http::make_response_text(std::string& message) {
    std::ostringstream response;
    response << "HTTP/1.1 200 OK\r\n"
             << "Content-Type: text/plain\r\n" 
             << "Content-Length: " << message.length() << "\r\n" 
             <<  "\r\n"
             << message;
    return response.str();
}

int Http::get_port() {
    return protocol_port;
}

std::string Http::get_message() {
    return protocol_message;
}

const char * Http::get_message() const {
    return protocol_message.c_str();
}

int Http::run() {
    std::cout << get_port() << '\n';
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen {sizeof(address)};
    char buffer[1024] {};

    
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        std::cerr << "socket failed" << '\n';
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(get_port());

    
    if (bind(server_fd, reinterpret_cast<struct sockaddr *>(&address), sizeof(address)) < 0) {
        std::cerr << "bind failed" << '\n';
        exit(EXIT_FAILURE);
    }

    
    if (listen(server_fd, 3) < 0) {
        std::cerr << "listen" << '\n';
        exit(EXIT_FAILURE);
    }

    std::cout << "Server listening on port " << get_port() << '\n';

    while (true) {
        if ((new_socket = accept(server_fd, reinterpret_cast<struct sockaddr *>(&address), reinterpret_cast<socklen_t*>(&addrlen))) < 0) {
            std::cerr << "accept" << '\n';
            exit(EXIT_FAILURE);
        }

        
        read(new_socket, buffer, 1024);
        std::cout << "Received: " << buffer << '\n';

        
        std::string response {make_response_html(protocol_message)};
        send(new_socket, response.c_str(), response.length(), 0);
        std::cout << "Response sent" << '\n';

        close(new_socket);
    }

    return 0;
}


