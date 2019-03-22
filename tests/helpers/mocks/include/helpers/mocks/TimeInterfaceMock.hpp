#pragma once
#include <string>
#include "interfaces/time_interface/TimeInterface.hpp"

namespace helpers {
namespace mocks {
struct TimeInterfaceMock final : public interfaces::TimeInterface {
    MOCK_METHOD0(actualTime, interfaces::TimePoint());
    MOCK_METHOD0(startTime, interfaces::TimePoint());
};
}  // namespace mocks
}  // namespace helpers
