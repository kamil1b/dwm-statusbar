#include "modules/ConcreteBatteryInterface.hpp"
#include <fstream>

modules::ConcreteBatteryInterface::ConcreteBatteryInterface(const std::filesystem::path& dataPath)
    : dataPath(dataPath)
{
}

std::string modules::ConcreteBatteryInterface::getBatteryData()
{
    std::ifstream batteryDataFile { dataPath };
    std::string data;
    batteryDataFile >> data;
    batteryDataFile.close();
    return data;
}
