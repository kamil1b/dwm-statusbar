#include "helpers/mocks/TimeInterfaceMock.hpp"
#include "modules/Time.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <string>
#include <vector>

namespace {
} // namespace

struct TimeModuleFixture : public ::testing::Test {
    helpers::mocks::TimeInterfaceMock timeInterfaceMock;

protected:
    TimeModuleFixture() {}
};

TEST_F(TimeModuleFixture, testTimeFormat)
{
    time_t expectedTime { 1517627100 };
    interfaces::TimePoint timePoint {
        std::chrono::system_clock::from_time_t(expectedTime)
    };
    EXPECT_CALL(timeInterfaceMock, actualTime())
        .WillOnce(::testing::Return(timePoint));

    std::stringstream ss;
    ss << std::put_time(std::localtime(&expectedTime), "%d.%m %R");
    std::string expectedOutput { ss.str() };
    modules::Time timeModule { timeInterfaceMock, std::chrono::milliseconds { 0 } };

    const auto& output = timeModule.printModule();
    EXPECT_EQ(output, expectedOutput);
}
