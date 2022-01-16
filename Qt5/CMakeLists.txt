cmake_minimum_required(VERSION 3.19)

project(Qt5Questions)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 COMPONENTS Core Gui Widgets OpenGL Network)

add_subdirectory(undo)
add_subdirectory(custom_abstract_qgraphicsitem)
