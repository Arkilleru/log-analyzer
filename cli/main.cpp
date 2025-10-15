#include "../core/analyzer.h"
#include <iostream>

int main() {
    std::string path;
    std::getline(std::cin, path);

    Analyzer analysis;
    std::string report = analysis.analyzer(path);

    std::cout << report;

    return 0;
}