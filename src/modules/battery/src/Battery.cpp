#include "modules/Battery.hpp"
#include <filesystem>

namespace {
const std::filesystem::path batteryPath{ "/sys/class/power_supply/BAT0/capacity" };
}

std::string modules::Battery::getBatteryLevel()
{
    batteryLevelFile.open(batteryPath);
    int batteryLevel;
    batteryLevelFile >> batteryLevel;
    batteryLevelFile.close();
    return std::to_string(batteryLevel) + "%";
}

std::string modules::Battery::printModule()
{
    return getBatteryLevel();
}
