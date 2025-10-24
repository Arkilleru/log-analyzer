#include "tests.h"

TEST(ParserTest, NormalTest) {
    std::string line = "192.168.1.105 - - [15/Oct/2024:14:32:01 +0300] \"GET /api/users HTTP/1.1\" 200 1234";
    Parser parser;
    LogInformation data = parser.Parse(line);
    EXPECT_EQ(data.ip, "192.168.1.105");
    EXPECT_EQ(data.time, "15/Oct/2024:14:32:01 +0300");
    EXPECT_EQ(data.operation, "GET");
    EXPECT_EQ(data.url, "/api/users");
    EXPECT_EQ(data.status, 200);
    EXPECT_EQ(data.answer_size, 1234);
    EXPECT_TRUE(data.parse_success);
}

TEST(ParserTest, InvalidOneParametrTest) {
    std::string line = "192.168.1 - - [15/Oct/2024:14:32:01 +0300] \"GET /api/users HTTP/1.1\" 200 1234";
    Parser parser;
    LogInformation data = parser.Parse(line);
    EXPECT_FALSE(data.parse_success);
}

TEST(ParserTest, EmptyTest) {
    std::string line = "";
    Parser parser;
    LogInformation data = parser.Parse(line);
    EXPECT_FALSE(data.parse_success);
}

