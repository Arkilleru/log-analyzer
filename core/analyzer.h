#pragma once

#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <algorithm>
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
    int total_processed = 0;
    int failed_parses = 0;
    int successful_requests = 0;
    int error_requests = 0; 
};



class Parser {
private:
    std::regex nginx_pattern;
public:
    Parser() : nginx_pattern(R"(^(\d+\.\d+\.\d+\.\d+) - - \[(.*?)\] \"(\w+) (.*?) HTTP/.*?\" (\d+) (\d+))") {}

    LogInformation Parse(const std::string& line);
};


class Reporter {
private:
    std::string GenerateGeneralStats(const AnalysisResult& data);
    std::string GenerateIpErrorsTop(const AnalysisResult& data);
    std::string GenerateErrorTypes(const AnalysisResult& data);
    std::string GenerateTimeDistribution(const AnalysisResult& data);
    std::vector<std::pair<std::string, int>> ToSortedVector(const std::unordered_map<std::string, int>& mp);
public:
    std::string GenerateTextReport(const AnalysisResult& data);
};


class Statistics {
public:
    void Process(LogInformation& data, AnalysisResult& res);
    std::string ExtractHour(std::string& time);

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



class Analyzer {
private:
   Reader reader; 
   Parser parser;
   Reporter reporter;
   Statistics statistics;

public:
    std::string analyze(std::string& path);
};

