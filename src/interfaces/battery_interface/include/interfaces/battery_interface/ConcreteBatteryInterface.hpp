#pragma once

#include "interfaces/battery_interface/BatteryInterface.hpp"

namespace interfaces {
struct ConcreteBatteryInterface final : public interfaces::BatteryInterface {
    std::string getBatteryLevel() override;
    types::BatteryStatus getBatteryStatus() override;
};
} // namespace interfaces
