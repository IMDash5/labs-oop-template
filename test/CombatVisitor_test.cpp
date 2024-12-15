#include <gtest/gtest.h>
#include "../include/CombatVisitor.hpp"
#include "../include/NPC/Orc.hpp"
#include "../include/NPC/Druid.hpp"
#include "../include/NPC/SlaveTrader.hpp"
#include "../include/observers/ConsoleObserver.hpp"
#include <vector>
#include <memory>

TEST(CombatVisitorTest, OrcVsOrc)
{
    std::shared_ptr<NPC> orc1 = std::make_shared<Orc>(0, 0, "Orc1");
    std::shared_ptr<NPC> orc2 = std::make_shared<Orc>(1, 1, "Orc2");

    std::vector<std::shared_ptr<NPC>> npcs = {orc1, orc2};
    std::vector<std::shared_ptr<Observer>> observers;
    std::vector<std::shared_ptr<NPC>> toRemove;

    std::shared_ptr<CombatVisitor> visitor = std::make_shared<CombatVisitor>(orc1, 2.0, npcs, observers, toRemove);

    orc2->accept(visitor);

    EXPECT_EQ(toRemove.size(), 2); // Оба Orc должны быть убиты
}

TEST(CombatVisitorTest, OrcVsSlaveTrader)
{
    std::shared_ptr<NPC> orc = std::make_shared<Orc>(0, 0, "Orc1");
    std::shared_ptr<NPC> slaveTrader = std::make_shared<SlaveTrader>(1, 1, "SlaveTrader1");

    std::vector<std::shared_ptr<NPC>> npcs = {orc, slaveTrader};
    std::vector<std::shared_ptr<Observer>> observers;
    std::vector<std::shared_ptr<NPC>> toRemove;

    std::shared_ptr<CombatVisitor> visitor = std::make_shared<CombatVisitor>(orc, 2.0, npcs, observers, toRemove);

    slaveTrader->accept(visitor);

    EXPECT_EQ(toRemove.size(), 1); // SlaveTrader должен быть убит
    EXPECT_EQ(toRemove[0], slaveTrader);
}