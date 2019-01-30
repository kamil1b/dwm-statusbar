CMAKE_MINIMUM_REQUIRED(VERSION 2.8.11)

project(dwm-statusbar)

find_package(Boost REQUIRED COMPONENTS filesystem)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "" FORCE)
endif(NOT CMAKE_BUILD_TYPE)

option(BUILD_TESTS "Include test targets" ON)

add_subdirectory(3rdparty)

set(CUSTOM_COMPILE_FLAGS "-Werror -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wconversion -Wdouble-promotion -Wformat=2")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${CUSTOM_COMPILE_FLAGS} -std=c++14 -O3 -march=native")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${CUSTOM_COMPILE_FLAGS} -std=c++14 -O3 -march=native")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)

IF(BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests EXCLUDE_FROM_ALL)
ENDIF(BUILD_TESTS)
