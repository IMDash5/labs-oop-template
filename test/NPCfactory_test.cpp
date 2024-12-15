#include <gtest/gtest.h>
#include "../include/NPC/NPCfactory.hpp"

TEST(NPCFactoryTest, CreateNPC)
{
    std::shared_ptr<NPC> orc = NPCFactory::createNPC(1, 2, "Orc1", "Orc");
    std::shared_ptr<NPC> druid = NPCFactory::createNPC(3, 4, "Druid1", "Druid");
    std::shared_ptr<NPC> slaveTrader = NPCFactory::createNPC(5, 6, "SlaveTrader1", "SlaveTrader");

    EXPECT_NE(orc, nullptr);
    EXPECT_EQ(orc->getName(), "Orc1");
    EXPECT_EQ(orc->getType(), "Orc");

    EXPECT_NE(druid, nullptr);
    EXPECT_EQ(druid->getName(), "Druid1");
    EXPECT_EQ(druid->getType(), "Druid");

    EXPECT_NE(slaveTrader, nullptr);
    EXPECT_EQ(slaveTrader->getName(), "SlaveTrader1");
    EXPECT_EQ(slaveTrader->getType(), "SlaveTrader");

    std::shared_ptr<NPC> unknown = NPCFactory::createNPC(0, 0, "Unknown", "UnknownType");
    EXPECT_EQ(unknown, nullptr);
}