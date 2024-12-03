#include "../include/Orc.hpp"

std::string Orc::interact(NPC* other) {
    return name + " (Орк) убил " + other->name;
}

std::string Orc::getType() const {
    return "Orc";
}