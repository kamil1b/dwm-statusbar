#include "helpers/mocks/TimeInterfaceMock.hpp"
#include "modules/UpTime.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <memory>
#include <string>

namespace {
constexpr time_t startTimeT { 1517627100 };
} // namespace

struct UpTimeModuleFixture : public ::testing::Test {
    std::unique_ptr<modules::UpTime> upTimeModule;
    helpers::mocks::TimeInterfaceMock timeInterfaceMock;
    const interfaces::TimePoint startTime;

protected:
    UpTimeModuleFixture()
        : startTime { std::chrono::system_clock::from_time_t(startTimeT) }
    {
        EXPECT_CALL(timeInterfaceMock, startTime())
            .WillOnce(::testing::Return(startTime));
    }

    void expectOutput(const std::string& expectedOutput)
    {
        const auto& output = upTimeModule->printModule();
        EXPECT_EQ(output, expectedOutput);
    }
};

TEST_F(UpTimeModuleFixture, testOutputFormat)
{
    EXPECT_CALL(timeInterfaceMock, actualTime())
        .WillOnce(::testing::Return(startTime));

    upTimeModule = std::make_unique<modules::UpTime>(
        timeInterfaceMock, std::chrono::milliseconds { 0 });
    expectOutput({ "Up 00:00:00" });
}

TEST_F(UpTimeModuleFixture, testSecondsOutput)
{
    interfaces::TimePoint timePoint { startTime + std::chrono::seconds { 5 } };
    EXPECT_CALL(timeInterfaceMock, actualTime())
        .WillOnce(::testing::Return(timePoint));

    upTimeModule = std::make_unique<modules::UpTime>(
        timeInterfaceMock, std::chrono::milliseconds { 0 });
    expectOutput({ "Up 00:00:05" });
}

TEST_F(UpTimeModuleFixture, testMinutsOutput)
{
    interfaces::TimePoint timePoint { startTime + std::chrono::minutes { 54 } };
    EXPECT_CALL(timeInterfaceMock, actualTime())
        .WillOnce(::testing::Return(timePoint));

    upTimeModule = std::make_unique<modules::UpTime>(
        timeInterfaceMock, std::chrono::milliseconds { 0 });
    expectOutput({ "Up 00:54:00" });
}

TEST_F(UpTimeModuleFixture, testHoursOutput)
{
    interfaces::TimePoint timePoint { startTime + std::chrono::hours { 21 } };
    EXPECT_CALL(timeInterfaceMock, actualTime())
        .WillOnce(::testing::Return(timePoint));

    upTimeModule = std::make_unique<modules::UpTime>(
        timeInterfaceMock, std::chrono::milliseconds { 0 });
    expectOutput({ "Up 21:00:00" });
}
