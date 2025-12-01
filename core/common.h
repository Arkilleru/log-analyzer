#pragma once

#include <unordered_map>
#include <string>
#include <algorithm>

enum class LogFormat {
    Nginx,
    Apache,
    Unknown
};

inline std::string LogFormatToString(LogFormat format) {
    switch(format) {
        case LogFormat::Apache: return "Apache";
        case LogFormat::Nginx: return "Nginx";
        default: return "Unknow";
    }
}

struct LogInformation {
    std::string ip;
    std::string time;
    std::string operation;
    std::string url;
    int status;
    size_t answer_size;
    bool parse_success;
    LogFormat format;
};

struct AnalysisResult {
    std::unordered_map<std::string, int> error_counts;
    std::unordered_map<std::string, int> ip;
    std::unordered_map<std::string, int> time_distribution;
    std::unordered_map<LogFormat, int> format_counts;
    int total_processed = 0;
    int failed_parses = 0;
    int successful_requests = 0;
    int error_requests = 0;
};