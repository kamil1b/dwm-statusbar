#include "types/Module.hpp"

types::Module::Module(std::chrono::milliseconds delay)
    : refreshDelay { delay }
    , executor(&Module::refresh, this)
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
    bool continueRefresh = refreshDelay != std::chrono::seconds { 0 };

    do {
        mutex.lock();
        updateStatus();
        mutex.unlock();
        std::this_thread::sleep_for(refreshDelay);
    } while (continueRefresh);
}
