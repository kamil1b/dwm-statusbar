#include "config.hpp"
#include "external_api/dwm/Dwm.hpp"
#include "status_bar/StatusBar.hpp"
#include <chrono>
#include <thread>
int main()
{
    const status_bar::StatusBar statusBar{
        std::move(segments),
    };
    while (true) {
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(500ms);
        external_api::dwm::Dwm dwm{};
        dwm.printStatusBar(statusBar.getBar());
    }
    return 0;
}
