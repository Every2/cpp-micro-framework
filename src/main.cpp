#include "../include/http.hpp"

int main() {
    Http server(8080, "Hello World!");
    server.run();
    return 0;
}
