#include "modules/Time.hpp"
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

modules::Time::Time(interfaces::TimeInterface& timeInterface)
    : timeInterface { timeInterface }
{
}

std::string modules::Time::actualTime()
{
    const auto actualTime = timeInterface.actualTime();
    auto in_time_t = std::chrono::system_clock::to_time_t(actualTime);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%d.%m %R");
    return ss.str();
}

std::string modules::Time::printModule()
{
    return actualTime();
}
