#include "analyzer.h"

AnalysisResult Analyzer::analyze(const std::string& path) {
    reader_.OpenFile(path);

    AnalysisResult res;
    while(reader_.MoreLines()) {
        std::string str = reader_.ReadLine();
        LogInformation data = parser_.Parse(str);
        statistics_.Process(data, res);
    }

    reader_.CloseFile();

    return res;
}
