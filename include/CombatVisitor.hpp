#pragma once

#include "Visitor.hpp"
#include "NPC/NPC.hpp"
#include "observers/Observer.hpp"
#include <vector>
#include <memory>

class CombatVisitor : public Visitor
{
private:
    std::shared_ptr<NPC> attacker;
    double attackRange;
    std::vector<std::shared_ptr<NPC>> &npcs;
    std::vector<std::shared_ptr<Observer>> &observers;
    std::vector<std::shared_ptr<NPC>> &toRemove;

public:
    CombatVisitor(std::shared_ptr<NPC> attacker, double attackRange, std::vector<std::shared_ptr<NPC>> &npcs, std::vector<std::shared_ptr<Observer>> &observers, std::vector<std::shared_ptr<NPC>> &toRemove);

    void visit(std::shared_ptr<Orc> orc) override;
    void visit(std::shared_ptr<Druid> druid) override;
    void visit(std::shared_ptr<SlaveTrader> slaveTrader) override;

    static void notify(const std::string &event, std::vector<std::shared_ptr<Observer>> &observers);
};