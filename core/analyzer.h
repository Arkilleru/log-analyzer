#pragma once

#include "reader.h"
#include "parser.h"
#include "statistics.h"
#include <string>

class Analyzer {
private:
   Reader reader_; 
   Parser parser_;
   Statistics statistics_;

public:
    AnalysisResult analyze(const std::string& path);
};

