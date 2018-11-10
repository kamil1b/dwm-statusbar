#pragma once
#include <string>
#include "modules/BatteryInterface.hpp"

namespace helpers {
namespace mocks {
struct BatteryInterfaceMock final : public modules::BatteryInterface {
    MOCK_METHOD0(getBatteryData, std::string());
};
}  // namespace mocks
}  // namespace helpers
