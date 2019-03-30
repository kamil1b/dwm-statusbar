#include "modules/Time.hpp"
#include <ctime>
#include <iomanip>
#include <sstream>

modules::Time::Time(interfaces::TimeInterface& interface,
    std::chrono::milliseconds delay)
    : Module { delay }
    , timeInterface { interface }
{
    init();
}

std::string modules::Time::actualTime()
{
    const auto actualTime = timeInterface.actualTime();
    auto in_time_t = std::chrono::system_clock::to_time_t(actualTime);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%d.%m %R");
    return ss.str();
}

void modules::Time::updateStatus() { moduleStatus = actualTime(); }
