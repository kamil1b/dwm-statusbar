IF(BUILD_TESTS)
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -std=c++14 -O3 -march=native")
  add_subdirectory(googletest)
ENDIF(BUILD_TESTS)

