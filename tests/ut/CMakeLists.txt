add_subdirectory(modules)

add_custom_target(ut_build
  DEPENDS ${PROJECT_NAME}-battery-ut ${PROJECT_NAME}-time-ut
)

add_custom_target(ut
  COMMAND ${CMAKE_CTEST_COMMAND} --verbose
  DEPENDS ut_build
)
