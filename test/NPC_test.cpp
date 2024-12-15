#include <gtest/gtest.h>
#include "../include/NPC/NPC.hpp"
#include "../include/NPC/Orc.hpp"
#include "../include/NPC/Druid.hpp"
#include "../include/NPC/SlaveTrader.hpp"

TEST(NPCTest, CreateNPC)
{
  std::shared_ptr<NPC> orc = std::make_shared<Orc>(1, 2, "Orc1");
  std::shared_ptr<NPC> druid = std::make_shared<Druid>(3, 4, "Druid1");
  std::shared_ptr<NPC> slaveTrader = std::make_shared<SlaveTrader>(5, 6, "SlaveTrader1");

  EXPECT_EQ(orc->getName(), "Orc1");
  EXPECT_EQ(orc->getType(), "Orc");
  EXPECT_EQ(orc->getPosition(), std::make_pair(1, 2));

  EXPECT_EQ(druid->getName(), "Druid1");
  EXPECT_EQ(druid->getType(), "Druid");
  EXPECT_EQ(druid->getPosition(), std::make_pair(3, 4));

  EXPECT_EQ(slaveTrader->getName(), "SlaveTrader1");
  EXPECT_EQ(slaveTrader->getType(), "SlaveTrader");
  EXPECT_EQ(slaveTrader->getPosition(), std::make_pair(5, 6));
}

TEST(NPCTest, DistanceTo)
{
  std::shared_ptr<NPC> orc1 = std::make_shared<Orc>(0, 0, "Orc1");
  std::shared_ptr<NPC> orc2 = std::make_shared<Orc>(3, 4, "Orc2");

  EXPECT_DOUBLE_EQ(orc1->distanceTo(orc2), 5.0);
}