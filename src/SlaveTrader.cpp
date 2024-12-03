#include "../include/SlaveTrader.hpp"

std::string SlaveTrader::interact(NPC* other) {
    if (other->getType() == "Druid") {
        return name + " (Работорговец) убил " + other->name + " (Друид)";
    }
    return {};
}

std::string SlaveTrader::getType() const {
    return "SlaveTrader";
}