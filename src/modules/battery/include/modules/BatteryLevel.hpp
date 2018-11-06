#pragma once
#include "types/Module.hpp"
#include <fstream>

namespace modules {
struct BatteryLevel final : public types::Module {
    std::string printModule() override;

private:
    std::string getBatteryLevel();
    std::ifstream batteryLevelFile {};
};
}
