#pragma once

#include "npc.hpp"

class Druid : public NPC, public std::enable_shared_from_this<Druid>
{
public:
    Druid(int x, int y, const std::string &name) : NPC(x, y, name, "Druid") {}
    void accept(std::shared_ptr<Visitor> visitor) override{visitor->visit(shared_from_this());}
};