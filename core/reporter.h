#pragma once
#include "common.h"

#include <vector>

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