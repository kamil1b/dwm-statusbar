#include "status_bar/BarSegment.hpp"
#include "types/Module.hpp"

status_bar::BarSegment status_bar::addSegment(types::Module& module)
{
    return std::bind(&types::Module::printModule, &module);
}
