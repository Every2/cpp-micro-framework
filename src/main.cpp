#include "../include/http.hpp"

int main() {
    Http server(8080, "<html><body><h1>Hello, World!</h1></body></html>");
    server.run();
    return 0;
}
