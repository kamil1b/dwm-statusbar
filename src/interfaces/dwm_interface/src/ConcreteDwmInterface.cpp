#include "interfaces/dwm_interface/ConcreteDwmInterface.hpp"
#include <stdexcept>

#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wold-style-cast"
#endif // GNUC

interfaces::ConcreteDwmInterface::ConcreteDwmInterface()
{
    Display* dpy = XOpenDisplay(nullptr);
    if (dpy == nullptr) {
        throw std::runtime_error { "XOpenDisplay: Failed to open display" };
    }
    display = std::make_unique<Display>(*dpy);
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
