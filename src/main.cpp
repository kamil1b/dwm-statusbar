#include "config.hpp"
#include "interfaces/dwm_interface/ConcreteDwmInterface.hpp"
#include "status_bar/StatusBar.hpp"
#include <chrono>
#include <thread>

namespace {
using namespace std::chrono_literals;
constexpr auto delay { 300ms };
interfaces::ConcreteDwmInterface dwmInterfaces {};
} // namespace

int main()
{
    const status_bar::StatusBar statusBar {
        std::move(segments),
    };

    while (true) {
        std::this_thread::sleep_for(delay);
        dwmInterfaces.printStatusBar(statusBar.getBar());
    }
    return 0;
}
