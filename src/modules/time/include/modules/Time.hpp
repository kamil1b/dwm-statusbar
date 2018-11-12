#pragma once
#include "interfaces/time_interface/TimeInterface.hpp"
#include "types/Module.hpp"

namespace modules {
struct Time final : public types::Module {
    Time(interfaces::TimeInterface& timeInterface);
    std::string printModule() override;

private:
    interfaces::TimeInterface& timeInterface;
    std::string actualTime();
};
}
