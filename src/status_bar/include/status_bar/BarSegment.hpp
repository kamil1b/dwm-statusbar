#pragma once
#include <array>
#include <functional>
#include <string>
namespace status_bar {
struct BarSegment {
    const std::string text;
    const std::function<std::string()> exec;
};
auto constexpr segmentCount{ 2 };
using BarSegments = std::array<BarSegment, segmentCount>;
};
