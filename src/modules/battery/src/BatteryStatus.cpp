#include "modules/BatteryStatus.hpp"
#include "types/BatteryStatus.hpp"
#include <exception>
#include <string>

namespace {
types::BatteryStatus convertToBatteryStatus(const std::string& batteryStatus)
{
    if (batteryStatus == "Discharging") {
        return types::BatteryStatus::Discharging;
    } else if (batteryStatus == "Charging") {
        return types::BatteryStatus::Charging;
    }
    return types::BatteryStatus::AC;

    //TODO: add error handling
}
std::string getBatteryStatusLabel(const types::BatteryStatus& batteryStatus, const types::BatteryStatusLabels& batteryStatusLabels)
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
}

modules::BatteryStatus::BatteryStatus(
    const types::BatteryStatusLabels& statusLabels,
    modules::BatteryInterface& batteryInterface)
    : statusLabels { statusLabels }
    , batteryInterface { batteryInterface }
{
}

std::string modules::BatteryStatus::getBatteryStatus() const
{
    const auto status = batteryInterface.getBatteryData();
    const auto batteryStatus { convertToBatteryStatus(status) };
    return getBatteryStatusLabel(batteryStatus, {});
}

std::string modules::BatteryStatus::printModule()
{
    return getBatteryStatus();
}
