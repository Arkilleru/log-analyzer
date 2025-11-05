#pragma once
#include "core.h"

#include <fstream>

class Reader {
private:
    std::unique_ptr<std::ifstream> file;
    size_t line_number;

public:
    Reader() = default;
    ~Reader() = default;

    bool OpenFile(const std::string& path);
    std::string ReadLine();
    bool MoreLines();
    void CloseFile();
};