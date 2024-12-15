#include "DungeonMaster.hpp"
#include "Visitor.hpp"
#include "CombatVisitor.hpp"

#include "observers/ConsoleObserver.hpp"
#include "observers/FileObserver.hpp"


#include "NPC/NPCfactory.hpp"
#include "NPC/Orc.hpp"
#include "NPC/Druid.hpp"
#include "NPC/SlaveTrader.hpp"
#include "NPC/npc.hpp"

#include "observers/observer.hpp"
#include <iostream>
#include <memory>

int main() {
    // Создаем DungeonMaster
    DungeonMaster dungeonMaster;

    // Создаем наблюдателей
    std::vector<std::shared_ptr<Observer>> observers;
    observers.push_back(std::make_shared<ConsoleObserver>());

    // Добавляем NPC в DungeonMaster
    dungeonMaster.addNPC("Orc", "Orc1", 0, 0);
    dungeonMaster.addNPC("Druid", "Druid1", 1, 1);
    dungeonMaster.addNPC("SlaveTrader", "Trader1", 2, 2);

    // Выводим список NPC
    std::cout << "Initial NPCs:" << std::endl;
    dungeonMaster.printNPCs();

    // Начинаем бой с дистанцией 5
    std::cout << "\nStarting combat with distance 5..." << std::endl;
    dungeonMaster.startCombat(5);

    // Выводим список NPC после боя
    std::cout << "\nNPCs after combat:" << std::endl;
    dungeonMaster.printNPCs();

    // Сохраняем NPC в файл
    std::cout << "\nSaving NPCs to file 'npcs.txt'..." << std::endl;
    dungeonMaster.saveToFile("npcs.txt");

    // Очищаем список NPC
    std::cout << "\nClearing NPCs..." << std::endl;
    dungeonMaster.clearNPCs();

    // Выводим список NPC после очистки
    std::cout << "\nNPCs after clearing:" << std::endl;
    dungeonMaster.printNPCs();

    // Загружаем NPC из файла
    std::cout << "\nLoading NPCs from file 'npcs.txt'..." << std::endl;
    dungeonMaster.loadFromFile("npcs.txt");

    // Выводим список NPC после загрузки
    std::cout << "\nNPCs after loading:" << std::endl;
    dungeonMaster.printNPCs();

    return 0;
}