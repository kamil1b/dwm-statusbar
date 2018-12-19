#include "interfaces/dwm_interface/ConcreteDwmInterface.hpp"
#include <stdexcept>

#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wold-style-cast"
#endif // GNUC

interfaces::ConcreteDwmInterface::ConcreteDwmInterface()
{
    auto xDisplay = XOpenDisplay(nullptr);
    display = std::make_unique<Display>(*xDisplay);
    if (!display) {
        throw std::runtime_error { "XOpenDisplay: Failed to open display" };
    }
}

interfaces::ConcreteDwmInterface::~ConcreteDwmInterface()
{
    XStoreName(display.get(), DefaultRootWindow(display.get()), nullptr);
    XCloseDisplay(display.get());
}

void interfaces::ConcreteDwmInterface::printStatusBar(const std::string& statusBar)
{
    if (XStoreName(display.get(), DefaultRootWindow(display.get()), statusBar.c_str())
        < 0) {
        throw std::runtime_error { "XStoreName: Allocation failed" };
    }
    XFlush(display.get());
}
