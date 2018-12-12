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
};
modules::BatteryStatus batteryStatusModule {
    batteryInterface,
    {
        { "ﮤ" },
        { "" },
        { "ﮣ" },
    },
};
modules::Time timeModule { timeInterface };
modules::UpTime upTimeModule { timeInterface };
modules::Separator beginSeparator { " " };
modules::Separator separator { "  " };
modules::Separator endSeparator { " " };
}

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
