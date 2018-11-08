#pragma once
#include "modules/BatteryInterface.hpp"
#include "types/Module.hpp"
#include <memory>

namespace modules {
struct BatteryLevel final : public types::Module {
    BatteryLevel(modules::BatteryInterface& batteryIterface);
    std::string printModule() override;

private:
    std::string getBatteryLevel();
    modules::BatteryInterface& batteryInterface;
};
}
