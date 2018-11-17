#include "modules/UpTime.hpp"
#include <chrono>
#include <iomanip>
#include <sstream>

namespace {
template <typename T>
auto getSeconds(T duration)
{

    const auto minutes = std::chrono::duration_cast<std::chrono::minutes>(duration);
    const auto seconds = duration - minutes;

    return std::chrono::duration_cast<std::chrono::seconds>(seconds).count();
}

template <typename T>
auto getMinutes(T duration)
{

    const auto hours = std::chrono::duration_cast<std::chrono::hours>(duration);
    const auto minutes = duration - hours;

    return std::chrono::duration_cast<std::chrono::minutes>(minutes).count();
}

template <typename T>
auto getHours(T duration)
{

    return std::chrono::duration_cast<std::chrono::hours>(duration).count();
}
} //namespace

modules::UpTime::UpTime(interfaces::TimeInterface& interface)
    : timeInterface { interface }
    , startTimePoint { timeInterface.actualTime() }
{
}

std::string modules::UpTime::printModule()
{
    return getUpTime();
}

std::string modules::UpTime::getUpTime()
{
    const auto timePoint = timeInterface.actualTime();
    const auto duration = timePoint - startTimePoint;
    const auto seconds = getSeconds(duration);
    const auto minutes = getMinutes(duration);
    const auto hours = getHours(duration);

    std::stringstream ss;
    ss << "Up " << std::setw(2) << std::setfill('0') << hours << ":" << std::setw(2) << std::setfill('0') << minutes << ":" << std::setw(2) << std::setfill('0') << seconds;
    return ss.str();
}
