#pragma once
#include <chrono>
#include <mutex>
#include <string>
#include <thread>

namespace types {
struct Module {
    Module(std::chrono::milliseconds);
    virtual ~Module();

    std::string printModule();

protected:
    void init();
    void refresh();

    virtual void updateStatus() = 0;
    std::string moduleStatus;

private:
    void refreshing();
    std::chrono::milliseconds refreshDelay;
    std::thread executor;
    std::mutex mutex;
};
} // namespace types
