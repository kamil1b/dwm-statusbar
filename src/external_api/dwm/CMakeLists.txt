set(MODULE_NAME dwm)
project(${MODULE_NAME} CXX)

message(STATUS "Configuring ${MODULE_NAME}")

set(SOURCES
    src/Dwm.cpp
)

set(HEADERS
    include/external_api/Dwm.hpp
)

add_library(${MODULE_NAME} STATIC ${SOURCES} ${HEADERS})

add_library(external_api::${MODULE_NAME} ALIAS ${MODULE_NAME})

target_include_directories(${MODULE_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
