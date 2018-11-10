set(MODULE_NAME battery_interface)
project(${MODULE_NAME} CXX)

message(STATUS "Configuring ${MODULE_NAME}")

set(SOURCES
    src/ConcreteBatteryInterface.cpp
)

set(HEADERS
    include/interfaces/battery_interface/BatteryInterface.hpp
    include/interfaces/battery_interface/ConcreteBatteryInterface.hpp
)

add_library(${MODULE_NAME} STATIC ${SOURCES} ${HEADERS})

add_library(interfaces::${MODULE_NAME} ALIAS ${MODULE_NAME})

target_include_directories(${MODULE_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(${MODULE_NAME}
    PRIVATE
        types
        stdc++fs
)
