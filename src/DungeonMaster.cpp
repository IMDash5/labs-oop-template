#include "../include/DungeonMaster.hpp"
#include <random>
#include <ctime>

DungeonMaster::DungeonMaster() : gameRunning(true)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 99);

    for (int i = 0; i < 50; ++i)
    {
        int x = dist(gen);
        int y = dist(gen);
        std::string name = "NPC" + std::to_string(i);
        std::string type = (i % 3 == 0) ? "Orc" : (i % 3 == 1) ? "Druid" : "SlaveTrader";
        addNPC(NPCFactory::createNPC(x, y, name, type));
    }
}

void DungeonMaster::addNPC(const std::shared_ptr<NPC> &npc){
    std::lock_guard<std::mutex> lock(npcsMutex);
    npcs.push_back(npc);}

void DungeonMaster::addObserver(const std::shared_ptr<Observer> &observer){observers.push_back(observer);}

void DungeonMaster::removeObserver(const std::shared_ptr<Observer> &observer)
{
    auto it = std::find(observers.begin(), observers.end(), observer);
    if (it != observers.end())
    {
        observers.erase(it);
    }
}

void DungeonMaster::removeNPC(const std::shared_ptr<NPC> &npc, std::vector<std::shared_ptr<NPC>> &npcs)
{
    auto it = std::find(npcs.begin(), npcs.end(), npc);
    if (it != npcs.end())
    {
        npcs.erase(it);
    }
}

void DungeonMaster::getNPCs(std::vector<std::shared_ptr<NPC>> &npcs)
{
    std::lock_guard<std::mutex> lock(npcsMutex);
    npcs = this->npcs;
}

void DungeonMaster::clearNPCs(){
    std::lock_guard<std::mutex> lock(npcsMutex);
    npcs.clear();}

void DungeonMaster::printNPCList()
{
    std::lock_guard<std::mutex> lock(npcsMutex);
    if (npcs.empty())
    {
        
        std::cout << "NPC List is empty" << std::endl;
    }
    else
    {
        std::cout << "NPC List:" << std::endl;
        for (const auto &npc : npcs)
        {
            npc->printInfo();
        }
    }
}

void DungeonMaster::saveNPCsToFile(const std::string &filename)
{
    std::ofstream outputFile(filename);
    if (!outputFile){throw OpeningFileException();}

    std::lock_guard<std::mutex> lock(npcsMutex);
    for (const auto &npc : npcs){
        outputFile << npc->getPosition().first << " "
                   << npc->getPosition().second << " "
                   << npc->getName() << " "
                   << npc->getType() << std::endl;
    }

    outputFile.close();
    std::cout << "NPCs saved to file: " << filename << std::endl;
}

void DungeonMaster::loadNPCsFromFile(const std::string &filename)
{
    std::ifstream inputFile(filename);
    if (!inputFile){throw OpeningFileException();}

    int x, y;
    std::string name, type;

    std::lock_guard<std::mutex> lock(npcsMutex);

    while (inputFile >> x >> y >> name >> type)
    {
        std::shared_ptr<NPC> npc = NPCFactory::createNPC(x, y, name, type);
        if (npc){addNPC(npc);}
        else{std::cerr << "Error creating NPC: " << type << ", " << name << ", (" << x << ", " << y << ")" << std::endl;}
    }
    inputFile.close();
    std::cout << "NPCs loaded from file: " << filename << std::endl;
}

void DungeonMaster::startGame()
{
    std::thread moveThread(&DungeonMaster::moveNPCsThread, this);
    std::thread combatThread(&DungeonMaster::combatThread, this);
    std::thread printThread(&DungeonMaster::printMapThread, this);

    moveThread.join();
    combatThread.join();
    printThread.join();
}

void DungeonMaster::stopGame()
{
    gameRunning = false;
    cv.notify_all();
}

void DungeonMaster::moveNPCsThread()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(-10, 10);

    while (gameRunning)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        std::lock_guard<std::mutex> lock(npcsMutex);
        for (auto &npc : npcs)
        {
            int dx = dist(gen);
            int dy = dist(gen);

            auto [currentX, currentY] = npc->getPosition();

            int newX = std::max(0, std::min(99, currentX + dx));
            int newY = std::max(0, std::min(99, currentY + dy));

            npc->setPosition(newX, newY);

            for (auto &other : npcs)
            {
                if (npc != other && npc->distanceTo(other) <= 10){checkForCombat(npc, other);}
            }
        }
    }
}

void DungeonMaster::combatThread()
{
    while (gameRunning)
    {
        std::unique_lock<std::mutex> lock(npcsMutex);
        cv.wait(lock);

        for (auto it = npcs.begin(); it != npcs.end();)
        {
            auto npc = *it;
            for (auto otherIt = it + 1; otherIt != npcs.end();)
            {
                auto other = *otherIt;
                if (npc->distanceTo(other) <= 10)
                {
                    performCombat(npc, other);
                    if (npc->isDead())
                    {
                        it = npcs.erase(it);
                        break;
                    }
                    if (other->isDead())
                    {
                        otherIt = npcs.erase(otherIt);
                        continue;
                    }
                }
                ++otherIt;
            }
            ++it;
        }
    }
}

void DungeonMaster::printMapThread()
{
    while (gameRunning)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));

        std::lock_guard<std::mutex> lock(npcsMutex);
        std::cout << "Map:" << std::endl;
        for (const auto &npc : npcs)
        {
            if (!npc->isDead())
            {
                auto [x, y] = npc->getPosition();
                std::cout << "Type: " << npc->getType() << ", Name: " << npc->getName() << ", Position: (" << x << ", " << y << ")" << std::endl;
            }
        }
    }
}

void DungeonMaster::checkForCombat(std::shared_ptr<NPC> npc1, std::shared_ptr<NPC> npc2)
{
    cv.notify_one();
}

void DungeonMaster::performCombat(std::shared_ptr<NPC> attacker, std::shared_ptr<NPC> defender)
{
    int attackPower = rollDice();
    int defensePower = rollDice();

    if (attackPower > defensePower)
    {
        defender->setDead(true);
        std::cout << attacker->getName() << " killed " << defender->getName() << std::endl;
    }
}

int DungeonMaster::rollDice()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 6);
    return dist(gen);
}

DungeonMaster::~DungeonMaster(){
    gameRunning = false;
    cv.notify_all();
    }