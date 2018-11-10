set(MODULE_NAME mocks)
project(${MODULE_NAME} CXX)

message(STATUS "Configuring ${MODULE_NAME}")

add_library(${MODULE_NAME} INTERFACE)
add_library(helpers::${MODULE_NAME} ALIAS ${MODULE_NAME})

target_include_directories(${MODULE_NAME} INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
