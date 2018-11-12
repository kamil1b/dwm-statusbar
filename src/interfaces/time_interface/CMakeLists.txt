set(MODULE_NAME time_interface)
project(${MODULE_NAME} CXX)

message(STATUS "Configuring ${MODULE_NAME}")

set(SOURCES
    src/ConcreteTimeInterface.cpp
)

set(HEADERS
    include/interfaces/time_interface/TimeInterface.hpp
    include/interfaces/time_interface/ConcreteTimeInterface.hpp
)

add_library(${MODULE_NAME} STATIC ${SOURCES} ${HEADERS})

add_library(interfaces::${MODULE_NAME} ALIAS ${MODULE_NAME})

target_include_directories(${MODULE_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
