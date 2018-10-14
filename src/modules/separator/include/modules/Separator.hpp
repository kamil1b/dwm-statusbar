#pragma once
#include "types/modules/Module.hpp"

namespace modules {
struct Separator final : public types::modules::Module {
    explicit Separator(std::string separator = " | ");
    std::string printModule() override;

private:
    const std::string separator;
};
}
