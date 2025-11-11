#pragma once

#include "reader.h"
#include "parser.h"
#include "statistics.h"
#include "reporter.h"
#include <string>

class Analyzer {
private:
   Reader reader_; 
   Parser parser_;
   Reporter reporter_;
   Statistics statistics_;

public:
    std::string analyze(std::string path);
};

