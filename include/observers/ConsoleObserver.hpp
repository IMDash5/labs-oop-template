#pragma once

#include "observer.hpp"

#include <iostream>

class ConsoleObserver : public Observer{
    void notify(const std::string& message) override {
        std::cout << message << std::endl;
    }
};