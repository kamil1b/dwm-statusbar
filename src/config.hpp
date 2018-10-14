#pragma once
#include "modules/Battery.hpp"
#include "modules/Separator.hpp"
#include "modules/Time.hpp"
#include "status_bar/BarSegment.hpp"
#include "types/modules/Module.hpp"

namespace {
modules::Battery batteryModule{};
modules::Time timeModule{};
modules::Separator separator{};

template <typename Module>
auto addSegment(Module module)
{
    return std::bind(&types::modules::Module::printModule, module);
}
}

status_bar::BarSegments segments{
    {
        addSegment(batteryModule),
        addSegment(separator),
        addSegment(timeModule),
    },
};
