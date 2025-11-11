#include "analyzer.h"

std::string Analyzer::analyze(std::string path) {
    reader_.OpenFile(path);

    AnalysisResult res;
    while(reader_.MoreLines()) {
        std::string str = reader_.ReadLine();
        LogInformation data = parser_.Parse(str);
        statistics_.Process(data, res);
    }

    reader_.CloseFile();
    std::string report = reporter_.GenerateTextReport(res);

    return report;
}