#include "analyzer.h"


bool Reader::OpenFile(const std::string& path) {
    file = std::make_unique<std::ifstream>(path);
    return file->is_open();
}

std::string Reader::ReadLine() {
    std::string line = "";
    std::getline(*file, line);
    return line;
}

bool Reader::MoreLines() {
    return file && file->peek() != EOF;
}

void Reader::CloseFile() {
    file.reset();
}
