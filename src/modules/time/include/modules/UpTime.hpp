#pragma once
#include "interfaces/time_interface/TimeInterface.hpp"
#include "types/Module.hpp"

namespace modules {
struct UpTime final : public types::Module {
    explicit UpTime(interfaces::TimeInterface& timeInterface);
    std::string printModule() override;

private:
    interfaces::TimeInterface& timeInterface;
    interfaces::TimePoint startTimePoint;
    std::string getUpTime();
};
}
