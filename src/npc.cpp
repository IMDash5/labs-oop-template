#include "../include/NPC.h"

NPC::NPC(const std::string& name, int x, int y) : name(name), x(x), y(y) {}

std::string NPC::getName() const{
    return name;
}


std::pair<int, int> NPC::getPosition() const{
    return {x, y};
}

double NPC::distanceTo(std::shared_ptr<NPC> other) const{
    return std::sqrt(std::pow(x - other->x, 2) + std::pow(y - other->y, 2));
}

void NPC::printInfo() const{
    std::cout << "Name: " << name << ", Position: (" << x << ", " << y << ")" << std::endl;
}