#include "../include/NPC/NPCfactory.hpp"

std::unique_ptr<NPC> NPCFactory::createNPC(const std::string& type, const std::string& name, int x, int y, int id) {
    if (type == "SlaveTrader") return std::make_unique<SlaveTrader>(name, type, x, y, id);
    if (type == "Druid") return std::make_unique<Druid>(name, type, x, y, id);
    if (type == "Orc") return std::make_unique<Orc>(name, type, x, y, id);
    throw std::invalid_argument("Unknown NPC type: " + type);
}