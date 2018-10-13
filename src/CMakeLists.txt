add_subdirectory(external_api)
add_subdirectory(modules)
add_subdirectory(status_bar)

add_executable(dwm-statusbar
    main.cpp
)

target_link_libraries(dwm-statusbar
    external_api::dwm
    modules::battery
    modules::time
    status_bar
)
