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
    std::string returnedStatus = "Charging";
    EXPECT_CALL(batteryInterfaceMock, getBatteryData())
        .WillOnce(::testing::Return(returnedStatus));

    auto status = batteryStatus.printModule();
    EXPECT_EQ(status, chargingLabel);
}

TEST_F(BatteryStatusFixture, SelectDischarginLabel) {
    std::string returnedStatus = "Discharging";
    EXPECT_CALL(batteryInterfaceMock, getBatteryData())
        .WillOnce(::testing::Return(returnedStatus));

    auto status = batteryStatus.printModule();
    EXPECT_EQ(status, dischargingLabel);
}

TEST_F(BatteryStatusFixture, SelectACLabel) {
    std::string returnedStatus = "AC";
    EXPECT_CALL(batteryInterfaceMock, getBatteryData())
        .WillOnce(::testing::Return(returnedStatus));

    auto status = batteryStatus.printModule();
    EXPECT_EQ(status, acLabel);
}
