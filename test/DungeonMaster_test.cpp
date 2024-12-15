#include <gtest/gtest.h>
#include "../include/DungeonMaster.hpp"
#include "../include/NPC/NPCfactory.hpp"

TEST(DungeonMasterTest, SaveLoadNPCs)
{
    DungeonMaster dungeonMaster;
    dungeonMaster.addNPC(NPCFactory::createNPC(1, 2, "Orc1", "Orc"));
    dungeonMaster.addNPC(NPCFactory::createNPC(3, 4, "Druid1", "Druid"));

    dungeonMaster.saveNPCsToFile("test_state.txt");

    dungeonMaster.clearNPCs();
    dungeonMaster.loadNPCsFromFile("test_state.txt");

    std::vector<std::shared_ptr<NPC>> npcs;
    dungeonMaster.getNPCs(npcs);

    EXPECT_EQ(npcs.size(), 2);
    EXPECT_EQ(npcs[0]->getName(), "Orc1");
    EXPECT_EQ(npcs[1]->getName(), "Druid1");
}