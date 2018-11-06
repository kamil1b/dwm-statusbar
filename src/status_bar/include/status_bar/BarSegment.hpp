#pragma once
#include <functional>
#include <string>
#include <vector>

namespace types {
struct Module;
}

namespace status_bar {
using BarSegment = std::function<std::string()>;
using BarSegments = std::vector<BarSegment>;

status_bar::BarSegment addSegment(types::Module& module);
}
