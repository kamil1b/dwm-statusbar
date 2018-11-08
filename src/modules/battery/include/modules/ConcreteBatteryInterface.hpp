#pragma once

#include "modules/BatteryInterface.hpp"
#include <filesystem>

namespace modules {
class ConcreteBatteryInterface final : public modules::BatteryInterface {
public:
    ConcreteBatteryInterface(const std::filesystem::path& dataPath);
    std::string getBatteryData() override;

private:
    std::filesystem::path dataPath;
};
}
