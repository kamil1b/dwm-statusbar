#include "interfaces/dwm_interface/ConcreteDwmInterface.hpp"
#include <stdlib.h>

namespace {
constexpr auto command = "xsetroot -name '";
}

void interfaces::ConcreteDwmInterface::printStatusBar(const std::string& statusBar)
{
    const auto exec_command = command + statusBar + "'";
    system(exec_command.c_str());
}
