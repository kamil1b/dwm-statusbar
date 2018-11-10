#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <string>
#include "helpers/mocks/BatteryInterfaceMock.hpp"
#include "modules/BatteryStatus.hpp"
#include "types/BatteryStatusLabels.hpp"

namespace {
std::string dischargingLabel{"D"};
std::string chargingLabel{"C"};
std::string acLabel{"AC"};
types::BatteryStatusLabels statusLabels{
    dischargingLabel,
    chargingLabel,
    acLabel,
};
}  // namespace

struct BatteryStatusFixture : public ::testing::Test {
    modules::BatteryStatus batteryStatus;
    helpers::mocks::BatteryInterfaceMock batteryInterfaceMock;

   protected:
    BatteryStatusFixture()
        : batteryStatus(statusLabels, batteryInterfaceMock) {}
};

TEST_F(BatteryStatusFixture, SelectCharginLabel) {
    EXPECT_CALL(batteryInterfaceMock, getBatteryStatus())
        .WillOnce(::testing::Return(types::BatteryStatus::Charging));

    auto status = batteryStatus.printModule();
    EXPECT_EQ(status, chargingLabel);
}

TEST_F(BatteryStatusFixture, SelectDischargingLabel) {
    EXPECT_CALL(batteryInterfaceMock, getBatteryStatus())
        .WillOnce(::testing::Return(types::BatteryStatus::Discharging));

    auto status = batteryStatus.printModule();
    EXPECT_EQ(status, dischargingLabel);
}

TEST_F(BatteryStatusFixture, SelectACLabel) {
    EXPECT_CALL(batteryInterfaceMock, getBatteryStatus())
        .WillOnce(::testing::Return(types::BatteryStatus::AC));

    auto status = batteryStatus.printModule();
    EXPECT_EQ(status, acLabel);
}
