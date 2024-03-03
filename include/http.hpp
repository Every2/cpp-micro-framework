#ifndef CPP_MICRO_FRAMEWORK_HTTP_HPP
#define CPP_MICRO_FRAMEWORK_HTTP_HPP

#include <string>
#include <string_view>
#include <iostream>
#include <sstream>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

class Http {

public:
    Http(int port, const std::string& message) : protocol_port(port), protocol_message(message) {}
    Http(int port, const char *message) : protocol_port(port), protocol_message(message) {}
    std::string make_response_text(std::string& message);
    std::string make_response_html(std::string& message);
    int get_port();
    int run();
    std::string get_message();
    const char * get_message() const;
private:
    int protocol_port;
    std::string protocol_message;
};


#endif
