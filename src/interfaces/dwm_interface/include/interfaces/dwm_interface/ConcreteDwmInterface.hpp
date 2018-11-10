#pragma once
#include "interfaces/dwm_interface/DwmInterface.hpp"
#include <string>

namespace interfaces {
struct ConcreteDwmInterface final : public interfaces::DwmInterface {
    void printStatusBar(const std::string& statusBar) override;
};
} // namespace interfaces
