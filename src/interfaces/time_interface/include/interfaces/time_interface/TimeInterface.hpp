#pragma once
#include <chrono>

namespace interfaces {
using TimePoint = std::chrono::time_point<std::chrono::system_clock>;
struct TimeInterface {
    virtual interfaces::TimePoint actualTime() = 0;
};
}
