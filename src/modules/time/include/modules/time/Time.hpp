#pragma once
#include "types/modules/Module.hpp"

namespace modules {
namespace time {
    struct Time final : public types::modules::Module {
        std::string printModule() override;

    private:
        std::string actualTime();
    };
};
};
