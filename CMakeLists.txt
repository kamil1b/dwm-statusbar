CMAKE_MINIMUM_REQUIRED(VERSION 2.8.11)

project(dwm-statusbar)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "" FORCE)
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -Werror -Wpedantic -std=c++17 -O3 -march=native")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Werror -Wpedantic -std=c++17")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
option(BUILD_TESTS "Include test targets" ON)

add_subdirectory(src)

IF(BUILD_TESTS)
  enable_testing()
  add_subdirectory(3rdparty EXCLUDE_FROM_ALL)
  #  add_subdirectory(test EXCLUDE_FROM_ALL)
ENDIF(BUILD_TESTS)
