add_executable(${PROJECT_NAME}-time-ut
    TimeModuleTests.cpp
    UpTimeModuleTests.cpp
)

target_link_libraries(${PROJECT_NAME}-time-ut
  modules::time
  helpers::mocks
  gtest
  gmock
  gtest_main
)

target_include_directories(${PROJECT_NAME}-time-ut
  PRIVATE
  ${PROJECT_SOURCE_DIR}/3rdparty/gtest
)

add_test(NAME ${PROJECT_NAME}-time-ut
  COMMAND ./${PROJECT_NAME}-time-ut
  WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)
