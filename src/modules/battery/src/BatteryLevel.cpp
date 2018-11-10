#include "modules/BatteryLevel.hpp"

modules::BatteryLevel::BatteryLevel(interfaces::BatteryInterface& batteryInterface)
    : batteryInterface { batteryInterface }
{
}

std::string modules::BatteryLevel::getBatteryLevel()
{
    const auto batteryLevel = batteryInterface.getBatteryLevel();
    return batteryLevel + "%";
}

std::string modules::BatteryLevel::printModule()
{
    return getBatteryLevel();
}
