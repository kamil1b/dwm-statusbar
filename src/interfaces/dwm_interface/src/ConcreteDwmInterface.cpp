#include "interfaces/dwm_interface/ConcreteDwmInterface.hpp"
#include <stdexcept>
#include <stdlib.h>
#include <sys/wait.h>

namespace {
constexpr auto command = "xsetroot -name '";
}

void interfaces::ConcreteDwmInterface::printStatusBar(const std::string& statusBar)
{
    const auto exec_command = command + statusBar + "'";
    const auto result = system(exec_command.c_str());
    if (not WIFEXITED(result))
        throw std::runtime_error { "xsetroot command not work correctly!" };
}
