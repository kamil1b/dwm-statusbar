#pragma once
#include "interfaces/dwm_interface/DwmInterface.hpp"
#include <memory>
#include <string>

#include <X11/Xlibint.h>

namespace interfaces {
struct ConcreteDwmInterface final : public interfaces::DwmInterface {
    ConcreteDwmInterface();
    ~ConcreteDwmInterface();
    void printStatusBar(const std::string& statusBar) override;

private:
    std::unique_ptr<Display> display;
};
} // namespace interfaces
