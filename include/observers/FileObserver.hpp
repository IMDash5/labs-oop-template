#pragma once

#include "Observer.hpp"
#include <fstream>
#include <vector>

class FileObserver : public Observer
{
private:
    std::ofstream outputFile;

public:
    explicit FileObserver(const std::string &filename);
    ~FileObserver();

    void onEvent(const std::string &event) override;
    void getLogs(std::vector<std::string> &lines, const std::string &filename);
};