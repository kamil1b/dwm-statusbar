#include "modules/BatteryLevel.hpp"

modules::BatteryLevel::BatteryLevel(interfaces::BatteryInterface& batteryInterface, const modules::BatterySigns& signs)
    : batteryInterface { batteryInterface }
    , signs { signs }
{
}

std::string modules::BatteryLevel::getBatteryLevel()
{
    const auto batteryLevel = batteryInterface.getBatteryLevel();
    return signs.batterySign + batteryLevel + signs.batteryPercentSign;
}

std::string modules::BatteryLevel::printModule()
{
    return getBatteryLevel();
}
