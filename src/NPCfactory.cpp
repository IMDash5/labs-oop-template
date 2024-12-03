#include "../include/NPCfactory.hpp"

std::unique_ptr<NPC> NPCFactory::createNPC(const std::string& type, const std::string& name, int x, int y) {
    if (type == "SlaveTrader") return std::make_unique<SlaveTrader>(name, x, y);
    if (type == "Druid") return std::make_unique<Druid>(name, x, y);
    if (type == "Orc") return std::make_unique<Orc>(name, x, y);
    throw std::invalid_argument("Unknown NPC type: " + type);
}