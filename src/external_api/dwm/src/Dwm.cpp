#include "external_api/dwm/Dwm.hpp"
#include <stdlib.h>

namespace {
constexpr auto command = "xsetroot -name '";
}

void external_api::dwm::Dwm::printStatusBar(const std::string& statusBar)
{
    const auto exec_command = command + statusBar + "'";
    system(exec_command.c_str());
}
