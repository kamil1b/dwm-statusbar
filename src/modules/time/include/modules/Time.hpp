#pragma once
#include "interfaces/time_interface/TimeInterface.hpp"
#include "types/Module.hpp"
#include <chrono>

namespace modules {
struct Time final : public types::Module {
    explicit Time(interfaces::TimeInterface&, std::chrono::milliseconds);
    void updateStatus() override;

private:
    interfaces::TimeInterface& timeInterface;
    std::string actualTime();
};
} // namespace modules
