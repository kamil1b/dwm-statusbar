#include "modules/BatteryLevel.hpp"

modules::BatteryLevel::BatteryLevel(modules::BatteryInterface& batteryInterface)
    : batteryInterface { batteryInterface }
{
}

std::string modules::BatteryLevel::getBatteryLevel()
{
    const auto batteryLevel = batteryInterface.getBatteryData();
    return batteryLevel + "%";
}

std::string modules::BatteryLevel::printModule()
{
    return getBatteryLevel();
}
