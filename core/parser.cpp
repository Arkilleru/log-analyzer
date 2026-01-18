#include "parser.h"

LogFormat Parser::DetectFormat(const std::string& line) {
    if (line.find("HTTP/1.0") != std::string::npos) {
        return LogFormat::Nginx;

    } else if (line.find("HTTP/1.1") != std::string::npos) {
        return LogFormat::Apache;
    }

    return LogFormat::Unknown;
}

void Parser::RegexParse(const std::string& line, const std::regex& pattern, LogInformation& data) {
    std::smatch matches;
    if (std::regex_match(line, matches, pattern)) {
        data.ip = matches[1];
        data.time = matches[2];
        data.operation = matches[3];
        data.url = matches[4];
        data.status = std::stoi(matches[5]);
        data.answer_size = std::stoul(matches[6]);
        data.parse_success = true;

        return;
    }

    data.parse_success = false;
}

LogInformation Parser::Parse(const std::string& line) {
    LogInformation data;
    data.format = DetectFormat(line);

    if (data.format == LogFormat::Apache) {
        RegexParse(line, apache_pattern_, data);
    }
    else if (data.format == LogFormat::Nginx) {
        RegexParse(line, nginx_pattern_, data);
    }
    else {
        data.parse_success = false;
    }


    return data; 
}