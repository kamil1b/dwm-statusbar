set(MODULE_NAME time)
project(${MODULE_NAME} CXX)

message(STATUS "Configuring ${MODULE_NAME}")

set(SOURCES
    src/Time.cpp
    src/UpTime.cpp
)

set(HEADERS
    include/modules/Time.hpp
    include/modules/UpTime.hpp
)

add_library(${MODULE_NAME} STATIC ${SOURCES} ${HEADERS})

add_library(modules::${MODULE_NAME} ALIAS ${MODULE_NAME})

target_include_directories(${MODULE_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(${MODULE_NAME}
    PRIVATE
        interfaces::time_interface
        types
)
