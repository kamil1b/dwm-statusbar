#pragma once
#include "modules/BatteryLevel.hpp"
#include "modules/BatteryStatus.hpp"
#include "modules/Separator.hpp"
#include "modules/Time.hpp"
#include "status_bar/BarSegment.hpp"

namespace {
const std::filesystem::path batteryStatusPath { "/sys/class/power_supply/BAT0/status" };

modules::BatteryLevel batteryLevelModule {};
modules::BatteryStatus batteryStatusModule {
    {},
    batteryStatusPath,
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
