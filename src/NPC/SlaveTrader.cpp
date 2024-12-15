#include "../../include/NPC/SlaveTrader.hpp"

SlaveTrader::SlaveTrader(int x, int y, const std::string &name) : NPC(x, y, name, "SlaveTrader") {}

void SlaveTrader::accept(std::shared_ptr<Visitor> visitor){
    visitor->visit(shared_from_this());
}