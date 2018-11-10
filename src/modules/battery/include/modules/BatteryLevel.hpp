#pragma once
#include "interfaces/battery_interface/BatteryInterface.hpp"
#include "types/Module.hpp"
#include <memory>

namespace modules {
struct BatteryLevel final : public types::Module {
    BatteryLevel(interfaces::BatteryInterface& batteryIterface);
    std::string printModule() override;

private:
    std::string getBatteryLevel();
    interfaces::BatteryInterface& batteryInterface;
};
}
