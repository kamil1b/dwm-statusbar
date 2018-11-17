#include "modules/BatteryLevel.hpp"

modules::BatteryLevel::BatteryLevel(interfaces::BatteryInterface& interface, const modules::BatterySigns& batterySigns)
    : batteryInterface { interface }
    , signs { batterySigns }
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
