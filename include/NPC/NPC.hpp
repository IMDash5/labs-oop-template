#pragma once

#include <string>
#include <memory>
#include <cmath>
#include <iostream>
#include "../../include/Visitor.hpp"

class NPC
{
protected:
    std::string name;
    std::string type;
    bool dead;
    int x, y;

public:

    NPC(int x, int y, const std::string &name, const std::string &type);
    virtual ~NPC() = default;

    std::string getName() const;
    std::string getType() const;
    std::pair<int, int> getPosition() const;
    void setPosition(int newX, int newY);

    virtual void accept(std::shared_ptr<Visitor> visitor) = 0;

    double distanceTo(std::shared_ptr<NPC> other) const;
    void printInfo() const;

    bool isDead() const;
    void setDead(bool dead);
};
