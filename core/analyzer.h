#pragma once
#include "core.h"

class Analyzer {
private:
   Reader reader; 
   Parser parser;
   Reporter reporter;
   Statistics statistics;

public:
    std::string analyze(std::string& path);
};

