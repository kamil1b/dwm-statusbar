#pragma once
#include "interfaces/battery_interface/BatteryInterface.hpp"
#include "types/Module.hpp"
#include <memory>

namespace modules {
struct BatterySigns {
    const std::string batterySign;
    const std::string batteryPercentSign;
};
struct BatteryLevel final : public types::Module {
    BatteryLevel(interfaces::BatteryInterface& batteryIterface, const modules::BatterySigns& signs);
    std::string printModule() override;

private:
    std::string getBatteryLevel();
    interfaces::BatteryInterface& batteryInterface;
    const BatterySigns signs;
};
}
