#pragma once
#include "interfaces/dwm_interface/DwmInterface.hpp"
#include <string>

namespace interfaces {
struct DwmInterface {
    virtual ~DwmInterface() = default;
    virtual void printStatusBar(const std::string& statusBar) = 0;
};
} // namespace interfaces
