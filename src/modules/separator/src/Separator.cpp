#include "modules/Separator.hpp"

modules::Separator::Separator(std::string separatorSign)
    : separator { separatorSign }
{
}

std::string modules::Separator::printModule()
{
    return separator;
}
