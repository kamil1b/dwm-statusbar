#include "modules/Separator.hpp"

modules::Separator::Separator(std::string separator)
    : separator{ separator }
{
}

std::string modules::Separator::printModule()
{
    return separator;
}
