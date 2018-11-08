#pragma once
#include <string>

namespace modules {
struct BatteryInterface {
    virtual ~BatteryInterface() = default;
    virtual std::string getBatteryData() = 0;
};
}
