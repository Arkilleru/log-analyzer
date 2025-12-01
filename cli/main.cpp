#include "../core/analyzer.h"
#include <iostream>

int main() {
    std::string path;
    std::cout << "Enter log file path:\n";
    std::getline(std::cin, path);

    Analyzer analysis;
    std::string report = analysis.analyze(path);

    std::cout << report;

    return 0;
}