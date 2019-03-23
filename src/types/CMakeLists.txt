set(MODULE_NAME types)
project(${MODULE_NAME} CXX)

message(STATUS "Configuring ${MODULE_NAME}")

set(SOURCES
    src/Module.cpp
)

set(HEADERS
  include/types/BatteryStatus.hpp
  include/types/BatteryStatusLabels.hpp
  include/types/Module.hpp
)

add_library(${MODULE_NAME} STATIC ${SOURCES} ${HEADERS})

target_include_directories(${MODULE_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(${MODULE_NAME}
    PRIVATE
        pthread
)
