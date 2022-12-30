# http://zetcode.com/gui/qt5/menusandtoolbars/
cmake_minimum_required(VERSION 3.25)

project(DependentApplication)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON )
set(CMAKE_AUTOUIC ON )

include(RPathHelpers) # RPath setup - early in the project!
include(GitVersioning)
include(LinuxDeployQt)

find_package(Qt5 COMPONENTS Core Gui Widgets
  REQUIRED CONFIG)

add_library(util SHARED
  util.cpp)

set(_app_name Dependent)
set(_app_fullname "Dependent fullname")
set(_app_comment "Dependent comment")

add_executable(${_app_name}
  main.cpp
  anothermenu.cpp
  )

target_link_libraries(${_app_name}
  util
  Qt5::Core
  Qt5::Gui
  Qt5::Widgets)

install(TARGETS
  util
  DESTINATION
  usr/lib
  )

install(TARGETS
  ${_app_name}
  DESTINATION
  usr/bin
  )

add_custom_target(AppDirInit ALL
  COMMAND
  python3 $ENV{CMAKE_UTIL_PATH}/LinuxDeployQt.py --root "${CMAKE_INSTALL_PREFIX}" --icon "${CMAKE_SOURCE_DIR}/Dependent.svg"  --name ${_app_name} --fullname ${_app_fullname}  --comment ${_app_comment}
  DEPENDS ${_app_name}
  VERBATIM
  USES_TERMINAL
  SOURCES ${CMAKE_SOURCE_DIR}/Dependent.svg
  )

install(CODE [[
  ]])

include(CPack)
