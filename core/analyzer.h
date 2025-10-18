#pragma once

#include <string>
#include <unordered_map>

struct LogInformation {
    std::string ip;
    std::string time;
    std::string operation;
    std::string url;
    std::string status;
    std::string answer_size;
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


class Parser {};


class Reporter {};


class Statistics {};

class Analyzer {
private:
   Reader reader; 
   Parser parser;
   Reporter reporter;
   Statistics statistics;

public:
    std::string analyzer(std::string path);
};

