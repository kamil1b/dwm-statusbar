project(dwm-statusbar)

CMAKE_MINIMUM_REQUIRED(VERSION 2.8.11)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost REQUIRED COMPONENTS filesystem)
LIST(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/scripts/cmake")

option(COVERAGE "CodeCoverage" OFF)
option(BUILD_TESTS "Include test targets" ON)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "" FORCE)
endif(NOT CMAKE_BUILD_TYPE)

if (CMAKE_BUILD_TYPE MATCHES Debug)
  if (COVERAGE MATCHES ON)
    include(CodeCoverage)
    APPEND_COVERAGE_COMPILER_FLAGS()
  endif()
endif()

add_subdirectory(3rdparty)
add_subdirectory(src)

set(CUSTOM_COMPILE_FLAGS "-Werror -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wconversion -Wdouble-promotion -Wformat=2")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${CUSTOM_COMPILE_FLAGS} -O3")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${CUSTOM_COMPILE_FLAGS} -g3")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif(BUILD_TESTS)

if (CMAKE_BUILD_TYPE MATCHES Debug)
  if (COVERAGE MATCHES ON)
      set (COVERAGE_GCOVR_EXCLUDES '.*/tests/.*' '.*/3rdparty/.*')
      SETUP_TARGET_FOR_COVERAGE_GCOVR_HTML(
        NAME ctest_coverage
        EXECUTABLE ctest -j ${PROCESSOR_COUNT}
        DEPENDENCIES ut_build
      )
  endif()
endif()
