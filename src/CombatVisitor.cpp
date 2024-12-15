#include "../include/CombatVisitor.hpp"
#include "../include/NPC/Orc.hpp"
#include "../include/NPC/Druid.hpp"
#include "../include/NPC/SlaveTrader.hpp"
#include "../include/DungeonMaster.hpp"
#include <iostream>
#include <algorithm>

BattleVisitor::BattleVisitor(std::shared_ptr<NPC> attacker, double attackRange, std::vector<std::shared_ptr<NPC>> &npcs, std::vector<std::shared_ptr<Observer>> &observers, std::vector<std::shared_ptr<NPC>> &toRemove) : attacker(attacker), attackRange(attackRange), npcs(npcs), observers(observers), toRemove(toRemove) {}

void BattleVisitor::notify(const std::string &event, std::vector<std::shared_ptr<Observer>> &observers)
{
    for (auto &observer : observers)
    {
        observer->onEvent(event);
    }
}

void BattleVisitor::visit(std::shared_ptr<Orc> orc)
{
    if (attacker->distanceTo(orc) > attackRange)
        return;

    if (attacker->getType() == "Orc")
    {
        notify(attacker->getName() + " (Orc) killed " + orc->getName() + " (Orc)", observers);
        notify(orc->getName() + " (Orc) killed " + attacker->getName() + " (Orc)", observers);
        toRemove.push_back(orc);
        toRemove.push_back(attacker);
    }
    else if (attacker->getType() == "SlaveTrader")
    {
        notify(orc->getName() + " (Orc) killed " + attacker->getName() + " (SlaveTrader)", observers);
        toRemove.push_back(attacker);
    }
    else if (attacker->getType() == "Druid")
    {
        notify(orc->getName() + " (Orc) killed " + attacker->getName() + " (Druid)", observers);
        toRemove.push_back(attacker);
    }
}

void BattleVisitor::visit(std::shared_ptr<Druid> druid)
{
    if (attacker->distanceTo(druid) > attackRange)
        return;

    if (attacker->getType() == "SlaveTrader")
    {
        notify(attacker->getName() + " (SlaveTrader) killed " + druid->getName() + " (Druid)", observers);
        toRemove.push_back(druid);
    }
}

void BattleVisitor::visit(std::shared_ptr<SlaveTrader> slaveTrader)
{
    if (attacker->distanceTo(slaveTrader) > attackRange)
        return;
    if (attacker->getType() == "Orc")
    {
        notify(attacker->getName() + " (Orc) killed " + slaveTrader->getName() + " (SlaveTrader)", observers);
        toRemove.push_back(slaveTrader);
    }
    else if (attacker->getType() == "Druid")
    {
        notify(slaveTrader->getName() + " (SlaveTrader) killed " + attacker->getName() + " (Druid)", observers);
        toRemove.push_back(attacker);
    }
}