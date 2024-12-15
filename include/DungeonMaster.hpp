#pragma once

#include "NPC/npc.hpp"
#include "CombatVisitor.hpp"
#include "observers/observer.hpp"
#include <vector>
#include <memory>
#include <string>

class DungeonMaster {
    std::vector<std::unique_ptr<NPC>> npcs;
    std::vector<std::shared_ptr<Observer>> observers;

    public:
        DungeonMaster();
        void addNPC(const std::string& type, const std::string& name, int x, int y);
        static void removeNPC(const std::shared_ptr<NPC> &npc, std::vector<std::shared_ptr<NPC>> &npcs);
        void saveToFile(const std::string& filename);
        void loadFromFile(const std::string& filename);
        void printNPCs() const;
        void getNPCs(std::vector<std::shared_ptr<NPC>> &npcs) const;
        void clearNPCs();
        void startCombat(int attackRange);
};
