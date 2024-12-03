#include "observer.hpp"

#include <iostream>

class ConsoleObserver : public Observer{
    void ConsoleObserver::notify(const std::string& message) override {
        std::cout << message << std::endl;
    }
};