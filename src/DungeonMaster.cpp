#include "DungeonMaster.hpp"
#include "NPC/Orc.hpp"
#include "NPC/Druid.hpp"
#include "NPC/SlaveTrader.hpp"
#include <fstream>
#include <iostream>
#include <set>

// Конструктор
DungeonMaster::DungeonMaster() {}

// Метод для добавления NPC
void DungeonMaster::addNPC(const std::string& type, const std::string& name, int x, int y) {
    if (type == "Orc") {
        npcs.push_back(std::make_unique<Orc>(name, type, x, y));
    } else if (type == "Druid") {
        npcs.push_back(std::make_unique<Druid>(name, type, x, y));
    } else if (type == "SlaveTrader") {
        npcs.push_back(std::make_unique<SlaveTrader>(name, type, x, y));
    } else {
        std::cerr << "Unknown NPC type: " << type << std::endl;
    }
}

// Метод для удаления NPC
void DungeonMaster::removeNPC(const std::shared_ptr<NPC>& npc, std::vector<std::shared_ptr<NPC>>& npcs) {
    npcs.erase(std::remove_if(npcs.begin(), npcs.end(), [&npc](const std::shared_ptr<NPC>& ptr) {
        return ptr.get() == npc.get();
    }), npcs.end());
}
// Метод для сохранения NPC в файл
void DungeonMaster::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    for (const auto& npc : npcs) {
        std::pair<int, int> pos = npc->getPosition();
        file << npc->getType() << " " << npc->getName() << " " << pos.first << " " << pos.second << std::endl;
    }

    file.close();
}

// Метод для загрузки NPC из файла
void DungeonMaster::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + filename);
    }

    std::string type, name;
    int x, y;
    while (file >> type >> name >> x >> y) {
        addNPC(type, name, x, y);
    }

    file.close();
}
// Метод для вывода списка NPC
void DungeonMaster::printNPCs() const {
    for (const auto& npc : npcs) {
        std::pair<int, int> pos = npc->getPosition();
        std::cout << "Type: " << npc->getType() << ", Name: " << npc->getName()
                  << ", Position: (" << pos.first << ", " << pos.second << ")" << std::endl;
    }
}

// Метод для получения списка NPC
void DungeonMaster::getNPCs(std::vector<std::shared_ptr<NPC>>& npcs) const {
    for (const auto& npc : this->npcs) {
        npcs.push_back(std::shared_ptr<NPC>(npc.get(), [](NPC*) {}));
    }
}

// Метод для очистки списка NPC
void DungeonMaster::clearNPCs() {
    npcs.clear();
}

// Метод для начала боя
void DungeonMaster::startCombat(int attackRange) {
    std::cout << "Starting combat with attack range: " << attackRange << std::endl;
    std::vector<std::shared_ptr<NPC>> sharedNPCs;
    getNPCs(sharedNPCs); // Получаем NPC в виде shared_ptr

    // Удаляем дубликаты из списка NPC
    std::set<std::shared_ptr<NPC>> uniqueNPCs(sharedNPCs.begin(), sharedNPCs.end());
    sharedNPCs.assign(uniqueNPCs.begin(), uniqueNPCs.end());

    std::cout << "NPCs before combat: " << sharedNPCs.size() << std::endl;

    std::vector<std::shared_ptr<NPC>> toRemove;
    CombatVisitor visitor(observers, sharedNPCs, toRemove, nullptr, attackRange);

    // Перебираем все пары NPC
    for (size_t i = 0; i < sharedNPCs.size(); ++i) {
        for (size_t j = i + 1; j < sharedNPCs.size(); ++j) {
            if (sharedNPCs[i] == sharedNPCs[j]) {
                continue; // Пропускаем сравнение с самим собой
            }

            std::cout << "Fighting between " << sharedNPCs[i]->getName() << " and " << sharedNPCs[j]->getName() << std::endl;
            std::vector<std::shared_ptr<NPC>> survivors;
            visitor.fight(sharedNPCs[i], sharedNPCs[j], survivors);

            // Обрабатываем выживших
            for (auto& survivor : survivors) {
                sharedNPCs.push_back(survivor);
            }

            // Выводим список NPC после каждого боя
            std::cout << "NPCs after fighting between " << sharedNPCs[i]->getName() << " and " << sharedNPCs[j]->getName() << ":" << std::endl;
            printNPCs();
        }
    }

    std::cout << "NPCs after combat: " << sharedNPCs.size() << std::endl;

    // Удаляем NPC, которые были помечены для удаления
    for (const auto& npc : toRemove) {
        removeNPC(npc, sharedNPCs);
    }

    // Обновляем основной список npcs
    npcs.clear();
    for (const auto& npc : sharedNPCs) {
        npcs.push_back(std::unique_ptr<NPC>(npc.get())); // Исправлено
    }
}