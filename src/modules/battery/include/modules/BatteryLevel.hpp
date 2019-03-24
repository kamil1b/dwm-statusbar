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
    BatteryLevel(interfaces::BatteryInterface& interface,
        const modules::BatterySigns& batterySigns);
    void updateStatus() override;

private:
    std::string getBatteryLevel();
    interfaces::BatteryInterface& batteryInterface;
    const BatterySigns signs;
};
} // namespace modules
