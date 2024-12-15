#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include "DungeonMaster.hpp"
#include "include/observers/ConsoleObserver.hpp"
#include "include/observers/FileObserver.hpp"

int main()
{
    DungeonMaster dungeonMaster;

    dungeonMaster.addObserver(std::make_shared<ConsoleObserver>());
    dungeonMaster.addObserver(std::make_shared<FileObserver>("game_log.txt"));

    std::cout << "Starting the game..." << std::endl;
    std::thread gameThread(&DungeonMaster::startGame, &dungeonMaster);

    std::this_thread::sleep_for(std::chrono::seconds(30));
    dungeonMaster.stopGame();

    gameThread.join();

    std::cout << "\nGame over. Survivors:" << std::endl;
    dungeonMaster.printNPCList();

    return 0;
}