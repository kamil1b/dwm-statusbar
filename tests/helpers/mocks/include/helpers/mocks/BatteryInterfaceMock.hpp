#pragma once
#include "interfaces/battery_interface/BatteryInterface.hpp"
#include "types/BatteryStatus.hpp"
#include <gmock/gmock.h>
#include <string>

namespace helpers {
namespace mocks {
    struct BatteryInterfaceMock final : public interfaces::BatteryInterface {
        MOCK_METHOD0(getBatteryLevel, std::string());
        MOCK_METHOD0(getBatteryStatus, types::BatteryStatus());
    };
} // namespace mocks
} // namespace helpers
