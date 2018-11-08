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

auto batteryLevelInterface = std::make_unique<modules::ConcreteBatteryInterface>(batteryLevelPath);
auto batteryStatusInterface = std::make_unique<modules::ConcreteBatteryInterface>(batteryStatusPath);
modules::BatteryLevel batteryLevelModule {
    std::move(batteryLevelInterface),
};
modules::BatteryStatus batteryStatusModule {
    {},
    std::move(batteryStatusInterface),
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
