#pragma once

#include <string>
#include <fstream>
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



class Reader {
private:
    std::unique_ptr<std::ifstream> file;
    size_t line_number;

public:
    Reader() = default;
    ~Reader() = default;

    bool OpenFile(const std::string& path);
    std::string ReadLine();
    bool MoreLines();
    void CloseFile();
};


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
    std::string analyzer(std::string& path);
};

