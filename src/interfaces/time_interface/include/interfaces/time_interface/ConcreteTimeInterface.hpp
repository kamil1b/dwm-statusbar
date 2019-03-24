#pragma once
#include "interfaces/time_interface/TimeInterface.hpp"
#include <chrono>

#pragma once
#include <chrono>

namespace interfaces {
struct ConcreteTimeInterface final : interfaces::TimeInterface {
    interfaces::TimePoint actualTime() override;
    interfaces::TimePoint startTime() override;
};
} // namespace interfaces
