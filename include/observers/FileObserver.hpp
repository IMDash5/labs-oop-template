#pragma once

#include "observer.hpp"
#include <fstream>

class FileObserver : public Observer {
    public:
        void notify(const std::string& message) {
            std::ofstream logFile("log.txt", std::ios::app);
            logFile << message << std::endl;
        }
};