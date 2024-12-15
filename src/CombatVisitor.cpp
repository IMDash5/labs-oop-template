#include "CombatVisitor.hpp"
#include "NPC/Orc.hpp"
#include "NPC/Druid.hpp"
#include "NPC/SlaveTrader.hpp"
#include <cmath>

// Конструктор с инициализацией ссылок
CombatVisitor::CombatVisitor(const std::vector<std::shared_ptr<Observer>>& observers,
                             std::vector<std::shared_ptr<NPC>>& npcs, std::vector<std::shared_ptr<NPC>>& toRemove,
                             std::shared_ptr<NPC> attacker, int attackRange)
    : observers(observers), npcs(npcs), toRemove(toRemove), attacker(attacker), attackRange(attackRange) {}

// Метод для вычисления расстояния между двумя NPC
double CombatVisitor::calculateDistance(const NPC* npc1, const NPC* npc2) {
    std::pair<int, int> pos1 = npc1->getPosition();
    std::pair<int, int> pos2 = npc2->getPosition();
    return std::sqrt(std::pow(pos1.first - pos2.first, 2) + std::pow(pos1.second - pos2.second, 2));
}

void CombatVisitor::visit(std::shared_ptr<Orc> orc) {
    if (attacker->distanceTo(orc) > attackRange) {
        std::cout << "Attacker is too far away." << std::endl;
        return;
    }

    // Если атакующий - Орк, то все в зоне атаки умирают
    if (attacker->getType() == "Orc") {
        notify(attacker->getName() + " (Orc) killed " + orc->getName() + " (Orc)");
        notify(orc->getName() + " (Orc) killed " + attacker->getName() + " (Orc)");
        toRemove.push_back(orc); // Удаляем обоих Орков
        toRemove.push_back(attacker);
    } else {
        // Если атакующий - другой тип, то атакуемый Орк убивает его
        notify(orc->getName() + " (Orc) killed " + attacker->getName() + " (" + attacker->getType() + ")");
        toRemove.push_back(attacker);
    }
}

void CombatVisitor::visit(std::shared_ptr<Druid> druid) {
    if (attacker->distanceTo(druid) > attackRange) {
        std::cout << "Attacker is too far away." << std::endl;
        return;
    }

    // Если атакующий - Работорговец, то Друид умирает
    if (attacker->getType() == "SlaveTrader") {
        notify(attacker->getName() + " (SlaveTrader) killed " + druid->getName() + " (Druid)");
        toRemove.push_back(druid);
        
    } 
    else if (attacker->getType() == "Orc") {
        notify(attacker->getName() + " (Orc) killed " + druid->getName() + " (Druid)");
        toRemove.push_back(attacker);
    }
    else {
        // Если атакующий - другой тип, то ничего не происходит
        notify(druid->getName() + " (Druid) does nothing.");
    }
}


void CombatVisitor::visit(std::shared_ptr<SlaveTrader> slaveTrader) {
    if (attacker->distanceTo(slaveTrader) > attackRange) {
        std::cout << "Attacker is too far away." << std::endl;
        return;
    }

    // Если атакующий - Друид, то ничего не происходит
    if (attacker->getType() == "Druid") {
        notify(slaveTrader->getName() + " (SlaveTrader) does nothing.");
    } else if (attacker->getType() == "Orc") {
        // Если атакующий - Орк, то Работорговец умирает
        notify(attacker->getName() + " (Orc) killed " + slaveTrader->getName() + " (SlaveTrader)");
        toRemove.push_back(slaveTrader);
    } else {
        // Если атакующий - другой тип, то ничего не происходит
        notify(slaveTrader->getName() + " (SlaveTrader) does nothing.");
    }
}

// Метод для начала боя между двумя NPC
void CombatVisitor::fight(std::shared_ptr<NPC> npc1, std::shared_ptr<NPC> npc2, std::vector<std::shared_ptr<NPC>>& survivors) {
    if (calculateDistance(npc1.get(), npc2.get()) <= attackRange) {
        std::string result1 = npc1->interact(npc2.get());
        std::string result2 = npc2->interact(npc1.get());

        notify(result1);
        notify(result2);

        if (result1.find("убил") != std::string::npos) {
            survivors.push_back(npc1);
        } else if (result2.find("убил") != std::string::npos) {
            survivors.push_back(npc2);
        } else {
            survivors.push_back(npc1);
            survivors.push_back(npc2);
        }
    } else {
        survivors.push_back(npc1);
        survivors.push_back(npc2);
    }
}

void CombatVisitor::notify(const std::string& message) {
    for (const auto& observer : observers) {
        observer->notify(message);
    }
}