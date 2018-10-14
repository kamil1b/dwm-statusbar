#pragma once
#include "types/modules/Module.hpp"
#include <fstream>

namespace modules {
struct Battery final : public types::modules::Module {
    std::string printModule() override;

private:
    std::string getBatteryLevel();
    std::ifstream batteryLevelFile{};
};
}
