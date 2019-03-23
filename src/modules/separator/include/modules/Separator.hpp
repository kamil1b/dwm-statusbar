#pragma once
#include "types/Module.hpp"

namespace modules {
struct Separator final : public types::Module {
    explicit Separator(std::string separatorSign = " | ");
    void updateStatus() override;

private:
    const std::string separator;
};
}
