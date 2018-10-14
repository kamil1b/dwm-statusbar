#pragma once
#include "types/modules/Module.hpp"

namespace modules {
struct Battery final : public types::modules::Module {
    std::string printModule() override;

private:
    std::string getBatteryLevel();
};
}
