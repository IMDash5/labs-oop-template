#pragma once

#include "Visitor.hpp"
#include "NPC/npc.hpp"
#include "observers/observer.hpp"
#include <vector>
#include <memory>
#include <cmath>

class CombatVisitor : public Visitor {
    int combatDistance;
    std::vector<std::shared_ptr<Observer>> observers;
    std::vector<std::shared_ptr<NPC>>& npcs;
    std::vector<std::shared_ptr<NPC>>& toRemove;
    std::shared_ptr<NPC> attacker;
    int attackRange;
    double calculateDistance(const NPC* npc1, const NPC* npc2);

public:
    CombatVisitor(const std::vector<std::shared_ptr<Observer>>& observers,
                  std::vector<std::shared_ptr<NPC>>& npcs, std::vector<std::shared_ptr<NPC>>& toRemove,
                  std::shared_ptr<NPC> attacker, int attackRange);

    void visit(std::shared_ptr<Orc> orc) override;
    void visit(std::shared_ptr<Druid> druid) override;
    void visit(std::shared_ptr<SlaveTrader> slaveTrader) override;

    void fight(std::shared_ptr<NPC> npc1, std::shared_ptr<NPC> npc2, std::vector<std::shared_ptr<NPC>>& survivors);

private:
    void notify(const std::string& message);
};