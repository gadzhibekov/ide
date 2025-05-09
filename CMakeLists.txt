cmake_minimum_required(VERSION 3.10)

project(ide VERSION 1.0 LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
 
find_package(Qt5 COMPONENTS Core Widgets Multimedia MultimediaWidgets REQUIRED)

include_directories(src)

set(SOURCES
    src/main.cpp
    src/main_window.cpp
    src/panel.cpp
    src/panel_item.cpp
    src/panel_tools.cpp
    src/welcome.cpp
    src/player.cpp
    src/redactor.cpp
    src/redactor_item.cpp

    src/utils/explorer.cpp
    src/utils/config.cpp
    src/utils/translator.cpp

    src/ui/label.cpp
    src/ui/button.cpp
    src/ui/dialog_window.cpp
    src/ui/widget.cpp
    src/ui/line_edit.cpp
)

set(HEADERS
    styles/styles.h
    src/main_window.h
    src/panel.h
    src/panel_item.h
    src/panel_tools.h
    src/welcome.h
    src/player.h
    src/redactor.h
    src/redactor_item.h

    src/utils/explorer.h
    src/utils/config.h
    src/utils/translator.h
    
    src/ui/label.h
    src/ui/button.h
    src/ui/dialog_window.h
    src/ui/widget.h
    src/ui/line_edit.h
)

message(STATUS "Qt5 Core version: ${Qt5Core_VERSION}")
message(STATUS "Qt5 Widgets version: ${Qt5Widgets_VERSION}")
message(STATUS "Qt5 Multimedia version: ${Qt5Multimedia_VERSION}")

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Widgets Qt5::Multimedia Qt5::MultimediaWidgets)
