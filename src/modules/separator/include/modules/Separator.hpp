#pragma once
#include "types/Module.hpp"

namespace modules {
struct Separator final : public types::Module {
    explicit Separator(std::string separator = " | ");
    std::string printModule() override;

private:
    const std::string separator;
};
}
