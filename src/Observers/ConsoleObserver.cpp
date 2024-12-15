#include "../../include/observers/ConsoleObserver.hpp"

void ConsoleObserver::onEvent(const std::string &event){
    std::cout << "Console Log: " << event << std::endl;
}