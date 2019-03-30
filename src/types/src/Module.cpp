#include "types/Module.hpp"
#include <functional>

types::Module::Module(std::chrono::milliseconds delay)
    : refreshDelay { delay }
{
}

types::Module::~Module() = default;

std::string types::Module::printModule()
{
    mutex.lock();
    std::string result = moduleStatus;
    mutex.unlock();
    return result;
}

void types::Module::refresh()
{
    mutex.lock();
    updateStatus();
    mutex.unlock();
}
void types::Module::refreshing()
{
    while (true) {
        refresh();
        std::this_thread::sleep_for(refreshDelay);
    }
}

void types::Module::init()
{
    bool continueRefresh = refreshDelay != std::chrono::seconds { 0 };
    if (continueRefresh) {
        executor = std::thread { &Module::refreshing, this };
    } else {
        refresh();
    }
}
