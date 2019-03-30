#include "helpers/mocks/BatteryInterfaceMock.hpp"
#include "modules/BatteryLevel.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <string>

namespace {
modules::BatterySigns signs { "", "%" };
}

struct BatteryLevelFixture : public ::testing::TestWithParam<int> {
    helpers::mocks::BatteryInterfaceMock batteryInterfaceMock;

protected:
    BatteryLevelFixture() {}
};

TEST_P(BatteryLevelFixture, GetBatteryLevel)
{
    const auto batteryLevel = std::to_string(GetParam());
    const auto expectedBatteryLevel = signs.batterySign + batteryLevel + signs.batteryPercentSign;
    EXPECT_CALL(batteryInterfaceMock, getBatteryLevel())
        .WillOnce(::testing::Return(batteryLevel));

    modules::BatteryLevel batteryLevelModule {
        batteryInterfaceMock,
        signs,
        std::chrono::milliseconds { 0 },
    };
    auto returnedBatteryLevel = batteryLevelModule.printModule();
    EXPECT_EQ(returnedBatteryLevel, expectedBatteryLevel);
}

INSTANTIATE_TEST_CASE_P(BatteryLevelTests, BatteryLevelFixture,
    ::testing::Range(0, 100, 5), );
