#include "interfaces/time_interface/ConcreteTimeInterface.hpp"

interfaces::TimePoint interfaces::ConcreteTimeInterface::actualTime()
{
    return std::chrono::system_clock::now();
}
