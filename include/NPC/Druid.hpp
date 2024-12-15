#pragma once

#include "NPC.hpp"
#include <memory>

class Druid : public NPC, public std::enable_shared_from_this<Druid>
{
public:
    Druid(int x, int y, const std::string &name);
    void accept(std::shared_ptr<Visitor> visitor) override;
};