cmake_minimum_required(VERSION 3.19)
project(Miner LANGUAGES CXX)

find_package(Qt6 6.9 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}          # Корень проекта
    ${CMAKE_CURRENT_SOURCE_DIR}/Core     # Папка Core
    ${CMAKE_CURRENT_SOURCE_DIR}/Visual   # Папка Visual
)

qt_add_executable(Miner
    WIN32 MACOSX_BUNDLE
    main.cpp
    Core/corelogic.h Core/corelogic.cpp
    Visual/visual.h Visual/visual.cpp
    Core/miner.h Core/miner.cpp
    any.qrc
)

target_link_libraries(Miner
    PRIVATE
        Qt::Core
        Qt::Widgets
)

install(TARGETS Miner
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET Miner
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
