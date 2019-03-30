#include "modules/Separator.hpp"

modules::Separator::Separator(std::string separatorSign)
    : Module { std::chrono::milliseconds { 0 } }
    , separator { separatorSign }
{
    init();
}

void modules::Separator::updateStatus() { moduleStatus = separator; }
