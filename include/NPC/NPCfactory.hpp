#pragma once

#include "Orc.hpp"
#include "SlaveTrader.hpp"
#include "Druid.hpp"

class NPCFactory {
    public:
        static std::unique_ptr<NPC> createNPC(const std::string& name, const std::string &type, int x, int y);
};