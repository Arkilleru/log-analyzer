#pragma once
#include "common.h"

class Statistics {
public:
    void Process(LogInformation& data, AnalysisResult& res);
    std::string ExtractHour(std::string& time);

};