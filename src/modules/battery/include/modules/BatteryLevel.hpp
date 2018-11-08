#pragma once
#include "modules/BatteryInterface.hpp"
#include "types/Module.hpp"
#include <memory>

namespace modules {
struct BatteryLevel final : public types::Module {
    BatteryLevel(std::unique_ptr<modules::BatteryInterface>&& batteryInterface);
    std::string printModule() override;

private:
    std::string getBatteryLevel();
    std::unique_ptr<modules::BatteryInterface> batteryInterface;
};
}
