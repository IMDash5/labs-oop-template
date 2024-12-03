#include "observer.hpp"

class FileObserver : public Observer {
    public:
        void FileObserver::notify(const std::string& message) {
            std::ofstream logFile("log.txt", std::ios::app);
            logFile << message << std::endl;
        }
}