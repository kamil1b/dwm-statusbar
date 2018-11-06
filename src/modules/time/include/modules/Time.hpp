#pragma once
#include "types/Module.hpp"

namespace modules {
struct Time final : public types::Module {
    std::string printModule() override;

private:
    std::string actualTime();
};
};
