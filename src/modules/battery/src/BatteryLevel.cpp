#include "modules/BatteryLevel.hpp"
#include <filesystem>

namespace {
const std::filesystem::path batteryLevelPath { "/sys/class/power_supply/BAT0/capacity" };
}

std::string modules::BatteryLevel::getBatteryLevel()
{
    batteryLevelFile.open(batteryLevelPath);
    int batteryLevel;
    batteryLevelFile >> batteryLevel;
    batteryLevelFile.close();
    return std::to_string(batteryLevel) + "%";
}

std::string modules::BatteryLevel::printModule()
{
    return getBatteryLevel();
}
