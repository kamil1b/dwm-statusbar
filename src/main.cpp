#include "external_api/dwm/Dwm.hpp"
#include "modules/battery/Battery.hpp"
#include "modules/time/Time.hpp"
#include "status_bar/BarSegment.hpp"
#include "status_bar/StatusBar.hpp"
#include <chrono>
#include <stdio.h>
#include <thread>

int main()
{
    status_bar::BarSegments segments{
        {
            {
                "Battery: ",
                modules::battery::getBatteryLevel,
            },
            {
                "",
                modules::time::actualTime,
            },
        }
    };
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
