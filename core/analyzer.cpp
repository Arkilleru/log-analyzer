#include "analyzer.h"

std::string Analyzer::analyze(std::string& path) {
    reader.OpenFile(path);

    AnalysisResult res;
    while(reader.MoreLines()) {
        std::string str = reader.ReadLine();
        LogInformation data = parser.Parse(str);
        statistics.Process(data, res);
    }

    reader.CloseFile();
    std::string report = reporter.GenerateTextReport(res);

    return report;
}