#pragma once

#include "npc.hpp"
#include <memory>


class Druid : public NPC, public std::enable_shared_from_this<Druid> {
    public:
        Druid(const std::string& name, const std::string& type, int x, int y, int id) : NPC(name, type, x, y, id) {}
        void accept(std::shared_ptr<Visitor> visitor) override{
            visitor->visit(shared_from_this());
        }
        std::string interact(const NPC* other) override{
            return getName() + " атакует " + other->getName();
        }

};
