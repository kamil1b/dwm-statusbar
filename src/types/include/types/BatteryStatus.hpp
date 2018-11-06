#pragma once
#include <cstdint>

namespace types {
enum class BatteryStatus : uint8_t {
    Discharging,
    Charging,
    AC,
};
}
