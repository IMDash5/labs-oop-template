#include <iostream>
#include <memory>
#include "DungeonMaster.hpp"
#include "include/observers/ConsoleObserver.hpp"
#include "include/observers/FileObserver.hpp"
#include "include/NPC/NPCfactory.hpp"

int main()
{
    DungeonMaster dungeonMaster;

    dungeonMaster.addObserver(std::make_shared<ConsoleObserver>());
    dungeonMaster.addObserver(std::make_shared<FileObserver>("game_log.txt"));

    dungeonMaster.addNPC(NPCFactory::createNPC(1, 1, "Orc1", "Orc"));
    dungeonMaster.addNPC(NPCFactory::createNPC(2, 2, "Druid1", "Druid"));
    dungeonMaster.addNPC(NPCFactory::createNPC(3, 3, "SlaveTrader1", "SlaveTrader"));
    dungeonMaster.addNPC(NPCFactory::createNPC(4, 4, "Orc2", "Orc"));
    dungeonMaster.addNPC(NPCFactory::createNPC(5, 5, "Druid2", "Druid"));

    std::cout << "Initial NPC List:" << std::endl;
    dungeonMaster.printNPCList();

    dungeonMaster.startBattle(5.0);

    std::cout << "\nNPC List after Battle:" << std::endl;
    dungeonMaster.printNPCList();

    try
    {
        dungeonMaster.saveNPCsToFile("game_state.txt");
        std::cout << "Game state saved to 'game_state.txt'." << std::endl;
    }
    catch (const OpeningFileException &e)
    {
        std::cerr << e.what() << std::endl;
    }

    dungeonMaster.clearNPCs();
    std::cout << "\nCleared NPC List. Loading from file..." << std::endl;

    try
    {
        dungeonMaster.loadNPCsFromFile("game_state.txt");
        std::cout << "Game state loaded from 'game_state.txt'." << std::endl;
    }
    catch (const OpeningFileException &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\nNPC List after Loading:" << std::endl;
    dungeonMaster.printNPCList();

    return 0;
}