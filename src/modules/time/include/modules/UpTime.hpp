#pragma once
#include "interfaces/time_interface/TimeInterface.hpp"
#include "types/Module.hpp"
#include <chrono>

namespace modules {
struct UpTime final : public types::Module {
    explicit UpTime(interfaces::TimeInterface&, std::chrono::milliseconds);
    void updateStatus() override;

private:
    interfaces::TimeInterface& timeInterface;
    interfaces::TimePoint startTimePoint;
    std::string getUpTime();
};
} // namespace modules
