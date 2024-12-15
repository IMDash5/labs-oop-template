#pragma once

#include "NPC/NPC.hpp"
#include "NPC/NPCfactory.hpp"
#include "observers/Observer.hpp"
#include "CombatVisitor.hpp"
#include <vector>
#include <memory>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdexcept>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <condition_variable>
#include <random>
#include <chrono>

class DungeonMaster
{
private:
    std::vector<std::shared_ptr<NPC>> npcs;
    std::vector<std::shared_ptr<Observer>> observers;
    std::shared_mutex npcsMutex;
    std::mutex cvMutex;
    std::condition_variable cv;
    bool gameRunning;

public:
    DungeonMaster();
    ~DungeonMaster();

    void addNPC(const std::shared_ptr<NPC> &npc);
    void addObserver(const std::shared_ptr<Observer> &observer);
    void removeObserver(const std::shared_ptr<Observer> &observer);
    void removeNPC(const std::shared_ptr<NPC> &npc, std::vector<std::shared_ptr<NPC>> &npcs);
    void getNPCs(std::vector<std::shared_ptr<NPC>> &npcs);
    void clearNPCs();
    void printNPCList();
    void saveNPCsToFile(const std::string &filename);
    void loadNPCsFromFile(const std::string &filename);
    void startGame();
    void stopGame();
private:
    void moveNPCsThread();
    void combatThread();
    void printMapThread();
    void checkForCombat(std::shared_ptr<NPC> npc1, std::shared_ptr<NPC> npc2);
    void performCombat(std::shared_ptr<NPC> attacker, std::shared_ptr<NPC> defender);
    int rollDice();
};

class OpeningFileException : public std::runtime_error
{
public:
    OpeningFileException() : std::runtime_error("Error while opening file") {}
};