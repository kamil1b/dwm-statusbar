#pragma once
#include "modules/Battery.hpp"
#include "modules/Separator.hpp"
#include "modules/Time.hpp"
#include "status_bar/BarSegment.hpp"

namespace {
modules::Battery batteryModule {};
modules::Time timeModule {};
modules::Separator separator {};
}

status_bar::BarSegments segments {
    {
        status_bar::addSegment(batteryModule),
        status_bar::addSegment(separator),
        status_bar::addSegment(timeModule),
    },
};
