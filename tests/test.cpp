#include "../include/http.hpp"
#include <gtest/gtest.h>

TEST(HttpServerTest, MakeResponseTest) {
    Http test_var {8080, "Hello, World!"};
    std::string expectedResponse {"HTTP/1.1 200 OK\r\nContent-Length: 13\r\n\r\nHello, World!"};
    std::string message {test_var.get_message()};
    std::string response {test_var.make_response(message)};
    EXPECT_EQ(response, expectedResponse);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

