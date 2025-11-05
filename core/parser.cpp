#include "parser.h"


LogInformation Parser::Parse(const std::string& line) {
    LogInformation data;
    std::smatch matches;

    if (std::regex_match(line, matches, nginx_pattern)) {
        data.ip = matches[1];
        data.time = matches[2];
        data.operation = matches[3];
        data.url = matches[4];
        data.status = std::stoi(matches[5]);
        data.answer_size = std::stoul(matches[6]);
        data.parse_success = true;

        return data;
    }

    data.parse_success = false;

    return data; 
}