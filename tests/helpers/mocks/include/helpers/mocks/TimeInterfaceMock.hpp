#pragma once
#include "interfaces/time_interface/TimeInterface.hpp"
#include <gmock/gmock.h>
#include <string>

namespace helpers {
namespace mocks {
    struct TimeInterfaceMock final : public interfaces::TimeInterface {
        MOCK_METHOD0(actualTime, interfaces::TimePoint());
        MOCK_METHOD0(startTime, interfaces::TimePoint());
    };
} // namespace mocks
} // namespace helpers
