#include "modules/BatteryLevel.hpp"

modules::BatteryLevel::BatteryLevel(interfaces::BatteryInterface& interface,
    const modules::BatterySigns& batterySigns,
    std::chrono::milliseconds delay)
    : Module { delay }
    , batteryInterface { interface }
    , signs { batterySigns }
{
    init();
}

std::string modules::BatteryLevel::getBatteryLevel()
{
    const auto batteryLevel = batteryInterface.getBatteryLevel();
    return signs.batterySign + batteryLevel + signs.batteryPercentSign;
}

void modules::BatteryLevel::updateStatus() { moduleStatus = getBatteryLevel(); }
