#pragma once
#include <chrono>

namespace interfaces {
using TimePoint = std::chrono::time_point<std::chrono::system_clock>;
struct TimeInterface {
    virtual ~TimeInterface() = default;
    virtual interfaces::TimePoint actualTime() = 0;
    virtual interfaces::TimePoint startTime() = 0;
};
} // namespace interfaces
