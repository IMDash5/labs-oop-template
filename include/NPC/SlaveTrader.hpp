#pragma once

#include "npc.hpp"

class SlaveTrader : public NPC, public std::enable_shared_from_this<SlaveTrader>
{
public:
    SlaveTrader(int x, int y, const std::string &name) : NPC(x, y, name, "SlaveTrader") {}
    void accept(std::shared_ptr<Visitor> visitor) override
    {
        visitor->visit(shared_from_this());
    }
};