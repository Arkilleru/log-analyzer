#pragma once
#include "core.h"

#include <algorithm>

class Statistics {
public:
    void Process(LogInformation& data, AnalysisResult& res);
    std::string ExtractHour(std::string& time);

};