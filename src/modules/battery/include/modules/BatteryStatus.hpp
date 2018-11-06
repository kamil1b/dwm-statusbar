#pragma once
#include "types/BatteryStatusLabels.hpp"
#include "types/Module.hpp"
#include <filesystem>

namespace modules {
struct BatteryStatus final : public types::Module {
    BatteryStatus(
        const types::BatteryStatusLabels& statusLabels,
        const std::filesystem::path& statusPath);
    std::string printModule() override;

private:
    std::string getBatteryStatus() const;
    const types::BatteryStatusLabels statusLabels;
    const std::filesystem::path statusPath;
};
}
