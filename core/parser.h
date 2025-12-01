#pragma once
#include "common.h"

#include <regex>

class Parser {
private:
    std::regex nginx_pattern_;
    std::regex apache_pattern_;
public:
    Parser() {
        nginx_pattern_ = R"(^(\d+\.\d+\.\d+\.\d+) - - \[([^\]]+)\] \"(\w+) (.*?) HTTP/1.1" (\d+) (\d+))";
        apache_pattern_ = R"(^(\d+\.\d+\.\d+\.\d+) - - \[([^\]]+)\] \"(\w+) (.*?) HTTP/1.0" (\d+) (\d+))"; 
    }

    LogFormat DetectFormat(const std::string& line);
    LogInformation Parse(const std::string& line);
    void RegexParse(const std::string& line, const std::regex& pattern, LogInformation&  data);
    
};