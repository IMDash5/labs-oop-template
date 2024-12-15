#include "../../include/NPC/Orc.hpp"

Orc::Orc(int x, int y, const std::string &name) : NPC(x, y, name, "Orc") {}

void Orc::accept(std::shared_ptr<Visitor> visitor){
    visitor->visit(shared_from_this());
}