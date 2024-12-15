#pragma once

#include "Visitor.hpp"

#include <string>
#include <memory>
#include <iostream>
#include <cmath>

class NPC {
    public:
        std::string name;
        std::string type;
        int x, y;

        NPC(const std::string& name, const std::string& type, int x, int y, int id) : name(name), type(type), x(x), y(y), id(id){}
        virtual ~NPC() = default;


        int getId() const { return id; }
        std::string getName() const;
        std::string getType() const;
        std::pair<int, int> getPosition() const;
        
        virtual void accept(std::shared_ptr<Visitor> visitor) = 0;

        double distanceTo(std::shared_ptr<NPC> other) const;

        void printInfo() const;

        virtual std::string interact(const NPC* other) = 0;

    private:
        int id; // Уникальный идентификатор

};