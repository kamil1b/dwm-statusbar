#pragma once
#include "types/BatteryStatus.hpp"
#include <string>

namespace interfaces {
struct BatteryInterface {
    virtual ~BatteryInterface() = default;
    virtual std::string getBatteryLevel() = 0;
    virtual types::BatteryStatus getBatteryStatus() = 0;
};
}
