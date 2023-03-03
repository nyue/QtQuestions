cmake_minimum_required(VERSION 3.25)

project(Qt6Questions)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package (Qt6
  COMPONENTS UiTools LinguistTools Widgets 3DCore 3DRender 3DExtras 3DInput
  REQUIRED)
set(q6q_link_libraries
  Qt6::Widgets
  )

# add_subdirectory(3D)
add_subdirectory(Widgets)
