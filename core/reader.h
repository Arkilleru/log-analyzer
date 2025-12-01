#pragma once
#include "common.h"

#include <fstream>
#include <memory> 

class Reader {
private:
    std::unique_ptr<std::ifstream> file_;

public:
    Reader() = default;
    ~Reader() = default;

    bool OpenFile(const std::string& path);
    std::string ReadLine();
    bool MoreLines();
    void CloseFile();
};