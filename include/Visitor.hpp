#pragma once

#include <memory>

class Orc;
class Druid;
class SlaveTrader;

class Visitor
{
public:
    virtual void visit(std::shared_ptr<Orc> orc) = 0;
    virtual void visit(std::shared_ptr<Druid> druid) = 0;
    virtual void visit(std::shared_ptr<SlaveTrader> slaveTrader) = 0;
    virtual ~Visitor() = default;
};