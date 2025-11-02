#include "analyzer.h"

std::string Reporter::GenerateGeneralStats(const AnalysisResult& data) {
    std::string stats = "\033[34m";
    stats += "General\n\n";
    stats += "\033[0m";

    stats += "Total requests - " + std::to_string(data.total_processed) + '\n';
    stats += "Sucсessful - " + std::to_string(data.successful_requests) + '\n';
    stats += "Failed - " + std::to_string(data.successful_requests) + '\n';
    stats += "Failed Parsing - " + std::to_string(data.failed_parses) + "\n\n";

    return stats;
}

std::vector<std::pair<std::string, int>> Reporter::ToSortedVector(const std::unordered_map<std::string, int>& mp) {
    std::vector<std::pair<std::string, int>> sorted(mp.begin(), mp.end());

    sort(sorted.begin(), sorted.end(), [](const auto& val1, const auto& val2) {
        return val1.second > val2.second;
    });

    return sorted;

}

std::string Reporter::GenerateIpErrorsTop(const AnalysisResult& data) {
    std::vector<std::pair<std::string, int>> sorted = ToSortedVector(data.ip);

    std::string ip = "\033[33m";
    ip += "Top errors IP\n\n";
    ip += "\033[0m";

    for(int i = 0; i < sorted.size() && i < 10; ++i) {
        ip += sorted[i].first + " - " + std::to_string(sorted[i].second) + '\n';
    }

    return ip + '\n';
}

std::string Reporter::GenerateErrorTypes(const AnalysisResult& data) {
    std::vector<std::pair<std::string, int>> sorted = ToSortedVector(data.error_counts);

    std::string types = "\033[32m";
    types += "Types errors IP\n\n";
    types += "\033[0m";

    for(int i = 0; i < sorted.size() && sorted[i].second != 0; ++i) {
        types += sorted[i].first + " - " + std::to_string(sorted[i].second) + '\n';
    }

    return types + '\n';
}

std::string Reporter::GenerateTimeDistribution(const AnalysisResult& data) {
    std::vector<std::pair<std::string, int>> sorted = ToSortedVector(data.time_distribution);

    std::string time = "\033[36m";
    time += "Time distribution\n\n";
    time += "\033[0m";

    for(int i = 0; i < sorted.size() && sorted[i].second != 0; ++i) {
        if (sorted[i].first.size() == 1) {
            time += "0";
        }

        time += sorted[i].first + " - " + std::to_string(sorted[i].second) + '\n';
    }

    return time + '\n';
}


std::string Reporter::GenerateTextReport(const AnalysisResult& data) {
    if (data.total_processed > 0) {
        std::string report = GenerateGeneralStats(data) ;
        report += GenerateIpErrorsTop(data);
        report += GenerateErrorTypes(data);
        report += GenerateTimeDistribution(data);

        return report;
    }

    return "invalid file format or file empty";
}