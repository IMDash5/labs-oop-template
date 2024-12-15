#include "../../include/NPC/Druid.hpp"

Druid::Druid(int x, int y, const std::string &name) : NPC(x, y, name, "Druid") {}

void Druid::accept(std::shared_ptr<Visitor> visitor){
    visitor->visit(shared_from_this());
}