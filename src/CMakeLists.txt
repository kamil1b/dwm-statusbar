add_subdirectory(interfaces)
add_subdirectory(modules)
add_subdirectory(status_bar)
add_subdirectory(types)

add_executable(dwm-statusbar
    main.cpp
)

target_link_libraries(dwm-statusbar
    interfaces::dwm_interface
    modules::battery
    modules::separator
    modules::time
    status_bar
)
