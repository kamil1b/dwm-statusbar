#include "config.hpp"
#include "external_api/Dwm.hpp"
#include "status_bar/StatusBar.hpp"
#include <chrono>
#include <thread>

namespace {
using namespace std::chrono_literals;
constexpr auto dalay{ 500ms };
}

int main()
{
    const status_bar::StatusBar statusBar{
        std::move(segments),
    };

    while (true) {
        std::this_thread::sleep_for(dalay);
        external_api::Dwm::printStatusBar(statusBar.getBar());
    }
    return 0;
}
