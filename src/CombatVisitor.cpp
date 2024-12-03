#include "CombatVisitor.hpp"

double CombatVisitor::calculateDistance(const NPC* npc1, const NPC* npc2) {
    return std::sqrt(std::pow(npc1->x - npc2->x, 2) + std::pow(npc1->y - npc2->y, 2));
}

CombatVisitor::CombatVisitor(int combatDistance, const std::vector<std::shared_ptr<Observer>>& observers)
    : combatDistance(combatDistance), observers(observers) {}

void CombatVisitor::fight(std::unique_ptr<NPC>& npc1, std::unique_ptr<NPC>& npc2, std::vector<std::unique_ptr<NPC>>& survivors) {
    if (calculateDistance(npc1.get(), npc2.get()) <= combatDistance) {
        std::string result1 = npc1->interact(npc2.get());
        std::string result2 = npc2->interact(npc1.get());

        for (const auto& observer : observers) {
            if (!result1.empty()) observer->notify(result1);
            if (!result2.empty()) observer->notify(result2);
        }

        if (npc1->getType() == "Orc" || (!result1.empty() && result1.find("убил") != std::string::npos)) {
            return;
        }

        survivors.push_back(std::move(result1.empty() ? npc1 : npc2));
    } else {
        survivors.push_back(std::move(npc1));
        survivors.push_back(std::move(npc2));
    }
}
