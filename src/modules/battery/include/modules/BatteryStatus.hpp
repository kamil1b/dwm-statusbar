#pragma once
#include "interfaces/battery_interface/BatteryInterface.hpp"
#include "types/BatteryStatusLabels.hpp"
#include "types/Module.hpp"
#include <memory>

namespace modules {
struct BatteryStatus final : public types::Module {
    BatteryStatus(
        interfaces::BatteryInterface& interface, const types::BatteryStatusLabels& batteryStatusLabels);
    std::string printModule() override;

private:
    std::string getBatteryStatus() const;
    const types::BatteryStatusLabels statusLabels;
    interfaces::BatteryInterface& batteryInterface;
};
}
