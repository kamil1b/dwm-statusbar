#pragma once
#include "types/Module.hpp"
#include <fstream>

namespace modules {
struct Battery final : public types::Module {
    std::string printModule() override;

private:
    std::string getBatteryLevel();
    std::ifstream batteryLevelFile {};
};
}
