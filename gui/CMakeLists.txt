set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

qt_add_executable(log-analyzer-gui
    main.cpp
    menu_window.h
    menu_window.cpp
    menu_window.ui
    main_window.h
    main_window.cpp
    main_window.ui
)

target_link_libraries(log-analyzer-gui
    PRIVATE Qt6::Widgets
)

qt_finalize_executable(log-analyzer-gui)
