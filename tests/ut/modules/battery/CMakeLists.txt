add_executable(${PROJECT_NAME}-battery-ut
  BatteryLevelTests.cpp
  BatteryStatusTests.cpp
)

target_link_libraries(${PROJECT_NAME}-battery-ut
  modules::battery
  helpers::mocks
  gtest
  gmock
  gtest_main
)

target_include_directories(${PROJECT_NAME}-battery-ut
  PRIVATE
  ${PROJECT_SOURCE_DIR}/3rdparty/gtest
)

add_test(NAME ${PROJECT_NAME}-battery-ut
  COMMAND ./${PROJECT_NAME}-battery-ut
  WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)
