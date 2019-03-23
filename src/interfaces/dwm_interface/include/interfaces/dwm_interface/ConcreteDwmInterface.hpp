#include "interfaces/dwm_interface/DwmInterface.hpp"
#include <X11/Xlibint.h>
#include <memory>
#include <string>

namespace interfaces {
struct ConcreteDwmInterface final : public interfaces::DwmInterface {
    ConcreteDwmInterface();
    ~ConcreteDwmInterface();
    void printStatusBar(const std::string& statusBar) override;

private:
    std::unique_ptr<Display> display;
};
} // namespace interfaces
