#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "helpers/mocks/TimeInterfaceMock.hpp"
#include "modules/Time.hpp"

namespace {}  // namespace

struct TimeModuleFixture : public ::testing::Test {
    modules::Time timeModule;
    helpers::mocks::TimeInterfaceMock timeInterfaceMock;

   protected:
    TimeModuleFixture() : timeModule{timeInterfaceMock} {}
};

TEST_F(TimeModuleFixture, testTimeFormat) {
    time_t expectedTime{1517627100};
    interfaces::TimePoint timePoint{
        std::chrono::system_clock::from_time_t(expectedTime)};
    EXPECT_CALL(timeInterfaceMock, actualTime())
        .WillOnce(::testing::Return(timePoint));

    std::stringstream ss;
    ss << std::put_time(std::localtime(&expectedTime), "%d.%m %R");
    std::string expectedOutput{ss.str()};
    const auto& output = timeModule.printModule();
    EXPECT_EQ(output, expectedOutput);
}
