#pragma once

#include <memory>

class NPC;
class Orc;
class SlaveTrader;
class Druid;

class Visitor
{
public:
    virtual void visit(const std::shared_ptr<Orc> orc) = 0;
    virtual void visit(const std::shared_ptr<SlaveTrader> slaveTrader) = 0;
    virtual void visit(const std::shared_ptr<Druid> druid) = 0;
    virtual ~Visitor() = default;
};