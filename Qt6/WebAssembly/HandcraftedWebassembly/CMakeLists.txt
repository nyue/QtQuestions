cmake_minimum_required(VERSION 3.29)

#project(MyWebassembly VERSION 0.1 LANGUAGES CXX)
project(HandcraftedWebassembly LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(hca
  main.cpp
  mainwindow.cpp
  mainwindow.h
  )

# target_link_options(hca "-s EXPORT_NAME=hca_entry")

target_link_libraries(hca PRIVATE Qt6::Widgets)

qt_finalize_executable(hca)
