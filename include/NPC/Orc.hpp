#pragma once

#include "NPC.hpp"
#include <memory>

class Orc : public NPC, public std::enable_shared_from_this<Orc>
{
public:
    Orc(int x, int y, const std::string &name);
    void accept(std::shared_ptr<Visitor> visitor) override;
};