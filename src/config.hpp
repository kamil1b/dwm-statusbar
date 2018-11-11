#pragma once
#include "interfaces/battery_interface/ConcreteBatteryInterface.hpp"
#include "modules/BatteryLevel.hpp"
#include "modules/BatteryStatus.hpp"
#include "modules/Separator.hpp"
#include "modules/Time.hpp"
#include "status_bar/BarSegment.hpp"
#include <memory>

namespace {
interfaces::ConcreteBatteryInterface batteryInterface {};
modules::BatteryLevel batteryLevelModule {
    batteryInterface,
    { "", "%" },
};
modules::BatteryStatus batteryStatusModule {
    {},
    batteryInterface,
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
