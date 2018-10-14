#pragma once
#include <string>

namespace types {
namespace modules {
    struct Module {
        virtual std::string printModule() = 0;
    };
}
}
