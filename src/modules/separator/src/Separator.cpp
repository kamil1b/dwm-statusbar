#include "modules/Separator.hpp"

modules::Separator::Separator(std::string separatorSign)
    : Module{std::chrono::milliseconds{0}}
    , separator { separatorSign }
{
}

void modules::Separator::updateStatus()
{
    moduleStatus = separator;
}
