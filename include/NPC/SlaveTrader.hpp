#pragma once

#include "NPC.hpp"
#include <memory>

class SlaveTrader : public NPC, public std::enable_shared_from_this<SlaveTrader>
{
public:
    SlaveTrader(int x, int y, const std::string &name);
    void accept(std::shared_ptr<Visitor> visitor) override;
};