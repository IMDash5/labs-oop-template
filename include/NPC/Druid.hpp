#pragma once

#include "npc.hpp"

class Druid : public NPC {
    public:
        Druid(const std::string& name, int x, int y) : NPC(name, x, y) {}
        void accept(std::shared_ptr<Visitor> visitor) override{
            visitor->visit(shared_from_this());
        }
};
