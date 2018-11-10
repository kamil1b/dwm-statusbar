add_subdirectory(modules)

add_custom_target(ut
  COMMAND ${CMAKE_CTEST_COMMAND} --verbose
  DEPENDS ${PROJECT_NAME}-battery-ut
)
