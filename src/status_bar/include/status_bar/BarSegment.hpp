#pragma once
#include <functional>
#include <string>
#include <vector>
namespace status_bar {
using BarSegment = std::function<std::string()>;
using BarSegments = std::vector<BarSegment>;
};
