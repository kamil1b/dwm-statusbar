#pragma once
#include <string>

namespace types {
struct Module {
    virtual std::string printModule() = 0;
};
}
