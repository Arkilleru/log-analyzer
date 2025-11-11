#include "reader.h"


bool Reader::OpenFile(const std::string& path) {
    file_ = std::make_unique<std::ifstream>(path);
    return file_->is_open();
}

std::string Reader::ReadLine() {
    std::string line = "";
    std::getline(*file_, line);
    return line;
}

bool Reader::MoreLines() {
    return file_ && file_->peek() != EOF;
}

void Reader::CloseFile() {
    file_.reset();
}
