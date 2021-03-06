#include "helpers/mocks/BatteryInterfaceMock.hpp"
#include "modules/BatteryStatus.hpp"
#include "types/BatteryStatusLabels.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <string>
#include <vector>

namespace {
std::string dischargingLabel { "1" };
std::string chargingLabel { "2" };
std::string acLabel { "3" };
types::BatteryStatusLabels statusLabels {
    dischargingLabel,
    chargingLabel,
    acLabel,
};
struct testParam {
    std::string statusLabel;
    types::BatteryStatus batteryStatus;
};
std::vector<testParam> testParams {
    { dischargingLabel, types::BatteryStatus::Discharging },
    { chargingLabel, types::BatteryStatus::Charging },
    { acLabel, types::BatteryStatus::AC },
};
} // namespace

struct BatteryStatusFixture : public ::testing::TestWithParam<testParam> {
    helpers::mocks::BatteryInterfaceMock batteryInterfaceMock;

protected:
    BatteryStatusFixture() {}
};

TEST_P(BatteryStatusFixture, SelectLabel)
{
    const auto testParam = GetParam();
    EXPECT_CALL(batteryInterfaceMock, getBatteryStatus())
        .WillOnce(::testing::Return(types::BatteryStatus::Charging));

    modules::BatteryStatus batteryStatus {
        batteryInterfaceMock,
        statusLabels,
        std::chrono::milliseconds { 0 },
    };
    auto status = batteryStatus.printModule();
    EXPECT_EQ(status, chargingLabel);
}

INSTANTIATE_TEST_CASE_P(BatteryStatusTests, BatteryStatusFixture,
    ::testing::ValuesIn(testParams), );
