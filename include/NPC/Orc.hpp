#pragma once

#include "npc.hpp"

class Orc : public NPC {
    public:
        Orc(const std::string& name, int x, int y) : NPC(name, x, y) {}
        void accept(std::shared_ptr<Visitor> visitor) override{
            visitor->visit(shared_from_this());
        }
};
