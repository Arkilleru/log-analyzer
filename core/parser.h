#pragma once
#include "common.h"

#include <regex>

class Parser {
private:
    std::regex nginx_pattern;
public:
    Parser() : nginx_pattern(R"(^(\d+\.\d+\.\d+\.\d+) - - \[(.*?)\] \"(\w+) (.*?) HTTP/.*?\" (\d+) (\d+))") {}

    LogInformation Parse(const std::string& line);
};