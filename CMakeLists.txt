cmake_minimum_required(VERSION 3.10)

project(ide VERSION 1.0 LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
 
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

include_directories(src)

set(SOURCES
    src/main.cpp
    src/main_window.cpp
    src/panel.cpp
    src/panel_item.cpp
    src/panel_tools.cpp
    src/explorer.cpp
    src/ui/label.cpp
    src/ui/button.cpp
)

set(HEADERS
    src/main_window.h
    src/panel.h
    src/panel_item.h
    src/panel_tools.h
    src/explorer.h
    src/ui/label.h
    src/ui/button.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Widgets)