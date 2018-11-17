#pragma once

#include "status_bar/BarSegment.hpp"
namespace status_bar {
class StatusBar {
public:
    explicit StatusBar(BarSegments&& barSegments);

    std::string getBar() const;

private:
    const BarSegments segments;
};
}
