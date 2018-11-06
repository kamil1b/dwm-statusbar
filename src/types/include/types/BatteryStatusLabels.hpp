#pragma once

#include <string>

namespace types {
struct BatteryStatusLabels {
    const std::string dischargingLabel { "D" };
    const std::string chargingLabel { "C" };
    const std::string acLabel { "AC" };
};
}
