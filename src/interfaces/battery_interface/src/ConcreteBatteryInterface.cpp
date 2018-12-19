#include "interfaces/battery_interface/ConcreteBatteryInterface.hpp"
#include <filesystem>
#include <fstream>

namespace {

const std::filesystem::path batteryStatusPath { "/sys/class/power_supply/BAT0/status" };
const std::filesystem::path batteryLevelPath { "/sys/class/power_supply/BAT0/capacity" };

types::BatteryStatus convertToBatteryStatus(const std::string& batteryStatus)
{
    if (batteryStatus == "Discharging") {
        return types::BatteryStatus::Discharging;
    } else if (batteryStatus == "Charging") {
        return types::BatteryStatus::Charging;
    }
    return types::BatteryStatus::AC;
}

std::string getBatteryData(const std::filesystem::path& dataPath)
{
    std::ifstream batteryDataFile { dataPath };
    std::string data;
    batteryDataFile >> data;
    batteryDataFile.close();
    return data;
}
} // namespace

std::string interfaces::ConcreteBatteryInterface::getBatteryLevel()
{
    return getBatteryData(batteryLevelPath);
}
types::BatteryStatus interfaces::ConcreteBatteryInterface::getBatteryStatus()
{
    const auto status = getBatteryData(batteryStatusPath);
    return convertToBatteryStatus(status);
}
