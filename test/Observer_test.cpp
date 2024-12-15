#include <gtest/gtest.h>
#include "../include/observers/ConsoleObserver.hpp"
#include "../include/observers/FileObserver.hpp"
#include <vector>
#include <fstream>

TEST(ObserverTest, ConsoleObserver)
{
    ConsoleObserver consoleObserver;
    testing::internal::CaptureStdout();

    consoleObserver.onEvent("Test event");

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Console Log: Test event\n");
}

TEST(ObserverTest, FileObserver)
{
    FileObserver fileObserver("test_log.txt");
    fileObserver.onEvent("Test event");

    std::vector<std::string> logs;
    fileObserver.getLogs(logs, "test_log.txt");

    EXPECT_EQ(logs.size(), 1);
    EXPECT_EQ(logs[0], "File Log: Test event");
}