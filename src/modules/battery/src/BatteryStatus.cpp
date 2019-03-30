#include "modules/BatteryStatus.hpp"
#include "types/BatteryStatus.hpp"
#include <exception>
#include <string>

namespace {
std::string getBatteryStatusLabel(
    const types::BatteryStatus& batteryStatus,
    const types::BatteryStatusLabels& batteryStatusLabels)
{
    switch (batteryStatus) {
    case types::BatteryStatus::Discharging:
        return batteryStatusLabels.dischargingLabel;
    case types::BatteryStatus::Charging:
        return batteryStatusLabels.chargingLabel;
    case types::BatteryStatus::AC:
        return batteryStatusLabels.acLabel;
    }
    throw std::out_of_range { "Out of range types::BatteryStatus" };
}
} // namespace

modules::BatteryStatus::BatteryStatus(
    interfaces::BatteryInterface& interface,
    const types::BatteryStatusLabels& batteryStatusLabels,
    std::chrono::milliseconds delay)
    : Module { delay }
    , statusLabels { batteryStatusLabels }
    , batteryInterface { interface }
{
    init();
}

std::string modules::BatteryStatus::getBatteryStatus() const
{
    const auto batteryStatus = batteryInterface.getBatteryStatus();
    return getBatteryStatusLabel(batteryStatus, statusLabels);
}

void modules::BatteryStatus::updateStatus()
{
    moduleStatus = getBatteryStatus();
}
