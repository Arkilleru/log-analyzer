#include "analyzer.h"

std::string Statistics::ExtractHour(std::string& time) {
    int pos = time.find(":");
    int start = pos + 1;

    return time.substr(start, 2);
}

void Statistics::Process(LogInformation& data, AnalysisResult& res) {
    if (!data.parse_success) {
        res.failed_parses++;
        return;
    }

    res.total_processed++;

    if (data.status < 400) {
        res.successful_requests++;
    }
    else {
        res.ip[data.ip]++;
        res.error_counts[std::to_string(data.status)]++;
        res.time_distribution[ExtractHour(data.time) + ":00"]++;
        res.error_requests++;
    }
}