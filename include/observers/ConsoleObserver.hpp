#pragma once

#include "Observer.hpp"
#include <iostream>

class ConsoleObserver : public Observer
{
public:
    void onEvent(const std::string &event) override;
};