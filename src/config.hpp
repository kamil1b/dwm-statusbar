#pragma once
#include "modules/battery/Battery.hpp"
#include "modules/time/Time.hpp"
#include "status_bar/BarSegment.hpp"

namespace {
modules::battery::Battery batteryModule{};
modules::time::Time timeModule{};
}

template <typename Module>
auto bind(Module module)
{
    return std::bind(&types::modules::Module::printModule, module);
}

status_bar::BarSegments segments{
    {
        {
            "Battery: ",
            bind(batteryModule),
        },
        {
            "",
            bind(timeModule),
        },
    },
};
