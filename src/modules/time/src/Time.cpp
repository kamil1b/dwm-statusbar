#include "modules/time/Time.hpp"
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

std::string modules::time::actualTime()
{
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%X");
    return ss.str();
}
