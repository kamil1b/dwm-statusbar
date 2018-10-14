#include "modules/Battery.hpp"
#include <filesystem>
#include <fstream>

namespace {
const std::filesystem::path battery_path{ "/sys/class/power_supply/BAT0/capacity" };
};

std::string modules::Battery::getBatteryLevel()
{
    std::ifstream ifstream{ battery_path };
    int battery_level;
    ifstream >> battery_level;
    return std::to_string(battery_level) + "%";
}

std::string modules::Battery::printModule()
{
    return getBatteryLevel();
}
