set(MODULE_NAME dwm_interface)
project(${MODULE_NAME} CXX)
find_package(X11)

message(STATUS "Configuring ${MODULE_NAME}")

set(SOURCES
    src/ConcreteDwmInterface.cpp
)

set(HEADERS
    include/interfaces/dwm_interface/ConcreteDwmInterface.hpp
    include/interfaces/dwm_interface/DwmInterface.hpp
)

add_library(${MODULE_NAME} STATIC ${SOURCES} ${HEADERS})

add_library(interfaces::${MODULE_NAME} ALIAS ${MODULE_NAME})

target_include_directories(${MODULE_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(${MODULE_NAME}
    PRIVATE
        X11
)
