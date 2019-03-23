#pragma once
#include <string>
#include <chrono>
#include <thread>
#include <mutex>

namespace types {
struct Module {
    Module(std::chrono::milliseconds);
    virtual ~Module();

    std::string printModule();

protected:
    void refresh();
    virtual void updateStatus() = 0;
    std::string moduleStatus;

private:
    std::chrono::milliseconds refreshDelay;
    std::thread executor;
    std::mutex mutex;
};
}
