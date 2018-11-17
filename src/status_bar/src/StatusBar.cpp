#include "status_bar/StatusBar.hpp"
#include "status_bar/BarSegment.hpp"

status_bar::StatusBar::StatusBar(BarSegments&& barSegments)
    : segments { barSegments }
{
}

std::string status_bar::StatusBar::getBar() const
{
    std::string result {};
    for (const auto& segment : segments) {
        result += segment();
    }
    return result;
}
