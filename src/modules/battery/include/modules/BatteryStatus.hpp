#pragma once
#include "modules/BatteryInterface.hpp"
#include "types/BatteryStatusLabels.hpp"
#include "types/Module.hpp"
#include <memory>

namespace modules {
struct BatteryStatus final : public types::Module {
    BatteryStatus(
        const types::BatteryStatusLabels& statusLabels,
        std::unique_ptr<modules::BatteryInterface>&& batteryInterface);
    std::string printModule() override;

private:
    std::string getBatteryStatus() const;
    const types::BatteryStatusLabels statusLabels;
    std::unique_ptr<modules::BatteryInterface> batteryInterface;
};
}
