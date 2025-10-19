#pragma once

#include <string>
#include <unordered_map>

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
    std::unordered_map<int, int> error_counts;
    std::unordered_map<std::string, int> ip;
    std::unordered_map<std::string, int> time_distribution;
    int total_processed = 0;
    int failed_parses = 0;
    int successful_requests = 0;
    int error_requests = 0; 
};




class Reader {};


class Parser {};


class Reporter {};


class Statistics {
public:
    AnalysisResult Process(LogInformation& data);
    std::string ExtractHour(std::string& time);

};

class Analyzer {
private:
   Reader reader; 
   Parser parser;
   Reporter reporter;
   Statistics statistics;

public:
    std::string analyzer(std::string& path);
};

