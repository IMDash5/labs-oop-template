#pragma once

#include "Orc.hpp"
#include "Druid.hpp"
#include "SlaveTrader.hpp"

class NPCFactory
{
public:
    static std::shared_ptr<NPC> createNPC(int x, int y, const std::string &name, const std::string &type);
};