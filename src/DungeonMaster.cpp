#include "DungeonMaster.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

DungeonEditor::DungeonEditor() {
    observers.push_back(std::make_shared<ConsoleObserver>());
    observers.push_back(std::make_shared<FileObserver>());
}

void DungeonEditor::addNPC(const std::string& type, const std::string& name, int x, int y) {
    if (x >= 0 && x <= 500 && y >= 0 && y <= 500) {
        npcs.push_back(NPCFactory::createNPC(type, name, x, y));
    } else {
        std::cout << "Координаты " << x << ", " << y << " вне допустимого диапазона!" << std::endl;
    }
}

void DungeonEditor::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Не удалось открыть файл для записи: " << filename << std::endl;
        return;
    }

    for (const auto& npc : npcs) {
        file << npc->getType() << "," << npc->name << "," << npc->x << "," << npc->y << "\n";
    }
}

void DungeonEditor::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Не удалось открыть файл для чтения: " << filename << std::endl;
        return;
    }

    npcs.clear();
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream stream(line);
        std::string type, name;
        int x, y;

        if (std::getline(stream, type, ',') &&
            std::getline(stream, name, ',') &&
            (stream >> x) && stream.ignore(1, ',') &&
            (stream >> y)) {
            addNPC(type, name, x, y);
        }
    }
}

void DungeonEditor::printNPCs() const {
    for (const auto& npc : npcs) {
        std::cout << npc->name << " (" << npc->getType() << ") - координаты: (" << npc->x << ", " << npc->y << ")\n";
    }
}

void DungeonEditor::startCombat(int combatDistance) {
    CombatVisitor combatVisitor(combatDistance, observers);
    std::vector<std::unique_ptr<NPC>> survivors;

    while (!npcs.empty()) {
        auto npc1 = std::move(npcs.back());
        npcs.pop_back();

        if (npcs.empty()) {
            survivors.push_back(std::move(npc1));
            break;
        }

        auto npc2 = std::move(npcs.back());
        npcs.pop_back();

        combatVisitor.fight(npc1, npc2, survivors);
    }

    npcs = std::move(survivors);
}
