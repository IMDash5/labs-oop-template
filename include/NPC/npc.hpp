#pragma once

#include "Visitor.hpp"

#include <string>
#include <memory>
#include <iostream>
#include <cmath>

class NPC {
    public:
        std::string name;
        int x, y;

        NPC(const std::string& name, int x, int y) : name(name), x(x), y(y) {}
        virtual ~NPC() = default;

        std::string getName() const;
        std::pair<int, int> getPosition() const;
        
        virtual void accept(std::shared_ptr<Visitor> visitor) = 0;

        double distanceTo(std::shared_ptr<NPC> other) const;
        void printInfo() const;
};