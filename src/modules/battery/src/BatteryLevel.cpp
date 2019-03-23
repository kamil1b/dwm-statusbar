#include "modules/BatteryLevel.hpp"

modules::BatteryLevel::BatteryLevel(interfaces::BatteryInterface& interface, const modules::BatterySigns& batterySigns)
    : Module{std::chrono::milliseconds{5000}}
    , batteryInterface { interface }
    , signs { batterySigns }
{
}

std::string modules::BatteryLevel::getBatteryLevel()
{
    const auto batteryLevel = batteryInterface.getBatteryLevel();
    return signs.batterySign + batteryLevel + signs.batteryPercentSign;
}

void modules::BatteryLevel::updateStatus()
{
    moduleStatus = getBatteryLevel();
}
