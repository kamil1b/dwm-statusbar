#pragma once
#include "interfaces/time_interface/TimeInterface.hpp"
#include "types/Module.hpp"

namespace modules {
struct Time final : public types::Module {
    explicit Time(interfaces::TimeInterface& interface);
    void updateStatus() override;

private:
    interfaces::TimeInterface& timeInterface;
    std::string actualTime();
};
} // namespace modules
