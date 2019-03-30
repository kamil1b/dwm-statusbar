#pragma once
#include "interfaces/battery_interface/ConcreteBatteryInterface.hpp"
#include "interfaces/time_interface/ConcreteTimeInterface.hpp"
#include "modules/BatteryLevel.hpp"
#include "modules/BatteryStatus.hpp"
#include "modules/Separator.hpp"
#include "modules/Time.hpp"
#include "modules/UpTime.hpp"
#include "status_bar/BarSegment.hpp"
#include <memory>

namespace {
interfaces::ConcreteBatteryInterface batteryInterface {};
interfaces::ConcreteTimeInterface timeInterface {};

modules::BatteryLevel batteryLevelModule {
    batteryInterface,
    { " ", "%" },
    std::chrono::milliseconds { 5000 },
};
modules::BatteryStatus batteryStatusModule {
    batteryInterface,
    {
        { "ﮤ" },
        { "" },
        { "ﮣ" },
    },
    std::chrono::milliseconds { 2000 },
};
modules::Time timeModule { timeInterface, std::chrono::milliseconds { 400 } };
modules::UpTime upTimeModule { timeInterface, std::chrono::milliseconds { 300 } };
modules::Separator beginSeparator { " " };
modules::Separator separator { "  " };
modules::Separator endSeparator { " " };
} // namespace

status_bar::BarSegments segments {
    {
        status_bar::addSegment(beginSeparator),
        status_bar::addSegment(batteryStatusModule),
        status_bar::addSegment(batteryLevelModule),
        status_bar::addSegment(separator),
        status_bar::addSegment(upTimeModule),
        status_bar::addSegment(separator),
        status_bar::addSegment(timeModule),
        status_bar::addSegment(endSeparator),
    },
};
