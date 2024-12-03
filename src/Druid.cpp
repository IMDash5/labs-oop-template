#include "../include/Druid.hpp"

std::string Druid::interact(NPC* other) {
    return name + " (Друид) никого не атакует";
}

std::string Druid::getType() const {
    return "Druid";
}