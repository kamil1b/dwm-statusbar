#include "external_api/Dwm.hpp"
#include <stdlib.h>

namespace {
constexpr auto command = "xsetroot -name '";
}

void external_api::Dwm::printStatusBar(const std::string& statusBar)
{
    const auto exec_command = command + statusBar + "'";
    system(exec_command.c_str());
}
