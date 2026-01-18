#include "../core/analyzer.h"
#include "reporter.h"
#include <iostream>

int main() {
    std::string path;
    std::cout << "Enter log file path:\n";
    std::getline(std::cin, path);

    Analyzer analysis;
    AnalysisResult result = analysis.analyze(path);
    Reporter reporter;
    std::string report = reporter.GenerateTextReport(result);

    std::cout << report;

    return 0;
}