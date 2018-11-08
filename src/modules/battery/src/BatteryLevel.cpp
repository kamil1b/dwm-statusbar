#include "modules/BatteryLevel.hpp"

modules::BatteryLevel::BatteryLevel(std::unique_ptr<modules::BatteryInterface>&& batteryInterface)
    : batteryInterface { std::move(batteryInterface) }
{
}

std::string modules::BatteryLevel::getBatteryLevel()
{
    const auto batteryLevel = batteryInterface->getBatteryData();
    return batteryLevel + "%";
}

std::string modules::BatteryLevel::printModule()
{
    return getBatteryLevel();
}
