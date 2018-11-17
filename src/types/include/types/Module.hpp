#pragma once
#include <string>

namespace types {
struct Module {
    virtual ~Module() = default;
    virtual std::string printModule() = 0;
};
}
