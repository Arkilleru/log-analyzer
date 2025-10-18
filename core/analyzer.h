#pragma once

#include <string>
#include <unordered_map>

#include <regex>

struct LogInformation {
    std::string ip;
    std::string time;
    std::string operation;
    std::string url;
    int status;
    size_t answer_size;
    bool parse_success;
};

struct AnalysisResult {
    std::unordered_map<std::string, int> error_counts;
    std::unordered_map<std::string, int> ip;
    std::unordered_map<std::string, int> time_distribution;
    int total_processed;
    int failed_parses;
    std::string analyze_problems;
};




class Reader {};


class Parser {
private:
    std::regex nginx_pattern;
public:
    Parser() : nginx_pattern(R"(^(\d+\.\d+\.\d+\.\d+) - - \[(.*?)\] \"(\w+) (.*?) HTTP/.*?\" (\d+) (\d+))") {}

    LogInformation Parse(const std::string& line);
};


class Reporter {};


class Statistics {};

class Analyzer {
private:
   Reader reader; 
   Parser parser;
   Reporter reporter;
   Statistics statistics;

public:
    std::string analyzer(std::string& path);
};

