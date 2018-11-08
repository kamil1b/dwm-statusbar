#pragma once
#include "modules/BatteryLevel.hpp"
#include "modules/BatteryStatus.hpp"
#include "modules/ConcreteBatteryInterface.hpp"
#include "modules/Separator.hpp"
#include "modules/Time.hpp"
#include "status_bar/BarSegment.hpp"
#include <memory>

namespace {
const std::filesystem::path batteryStatusPath { "/sys/class/power_supply/BAT0/status" };
const std::filesystem::path batteryLevelPath { "/sys/class/power_supply/BAT0/capacity" };

modules::ConcreteBatteryInterface batteryLevelInterface { batteryLevelPath };
modules::ConcreteBatteryInterface batteryStatusInterface = { batteryStatusPath };
modules::BatteryLevel batteryLevelModule {
    batteryLevelInterface,
};
modules::BatteryStatus batteryStatusModule {
    {},
    batteryStatusInterface,
};
modules::Time timeModule {};
modules::Separator separator {};
}

status_bar::BarSegments segments {
    {
        status_bar::addSegment(batteryStatusModule),
        status_bar::addSegment(separator),
        status_bar::addSegment(batteryLevelModule),
        status_bar::addSegment(separator),
        status_bar::addSegment(timeModule),
    },
};
