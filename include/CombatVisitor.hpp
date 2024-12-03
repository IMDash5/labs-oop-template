#include "npc.hpp"
#include "observer.hpp"
#include "Visitor.hpp"
#include <vector>
#include <memory>
#include <cmath>

class CombatVisitor : public Visitor{
    int combatDistance;
    std::vector<std::shared_ptr<Observer>> observers;
    std::vector<std::shared_ptr<NPC>> &npcs;
    std::vector<std::shared_ptr<NPC>> &toRemove;

    double calculateDistance(const NPC* npc1, const NPC* npc2);

    public:
        CombatVisitor(int combatDistance, const std::vector<std::shared_ptr<Observer>>& observers);
        void visit(std::shared_ptr<Orc> orc) override;
        void visit(std::shared_ptr<SlaveTrader> slaveTrader) override;
        void visit(std::shared_ptr<Druid> druid) override;
        void fight(std::unique_ptr<NPC>& npc1, std::unique_ptr<NPC>& npc2, std::vector<std::unique_ptr<NPC>>& survivors);
};