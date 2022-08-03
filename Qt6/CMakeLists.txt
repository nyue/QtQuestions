cmake_minimum_required(VERSION 3.19)

project(Qt6Questions)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package (Qt6
  COMPONENTS UiTools LinguistTools Widgets 3DCore 3DRender 3DExtras 3DInput
  REQUIRED)

add_subdirectory(3D)
