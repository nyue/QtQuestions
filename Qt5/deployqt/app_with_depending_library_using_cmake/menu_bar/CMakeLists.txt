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

find_package(Python3 COMPONENTS Interpreter)
find_package(Qt5 COMPONENTS Core Gui Widgets
  REQUIRED CONFIG)

set(USE_APPIMAGE OFF)
set(SHARED_LIBRARY_TARGET_DESTINATION usr/lib)
if (WIN32)
  set(SHARED_LIBRARY_TARGET_DESTINATION bin)
elseif (APPLE)
else (WIN32)
  # Assume Linux
  # LinuxDeployQt is tailored for AppImage and hence the directory structure is different
  set(USE_APPIMAGE ON)
endif()

add_library(util SHARED
  util.cpp)
if (WIN32)
   # CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS
   # WINDOWS_EXPORT_ALL_SYMBOLS

   # This is the non-lazy specific symbol export approach
   set_target_properties(util PROPERTIES LINK_FLAGS /EXPORT:somefunction)
endif (WIN32)

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
  RUNTIME DESTINATION ${SHARED_LIBRARY_TARGET_DESTINATION} COMPONENT Runtime
  LIBRARY DESTINATION ${SHARED_LIBRARY_TARGET_DESTINATION} COMPONENT Runtime
  )

install(TARGETS
  ${_app_name}
  DESTINATION
  ${SHARED_LIBRARY_TARGET_DESTINATION}
  )

if (USE_APPIMAGE)
add_custom_target(AppDirInit ALL
  COMMAND
  Python3::Interpreter $ENV{CMAKE_UTIL_PATH}/LinuxDeployQt.py --root "${CMAKE_INSTALL_PREFIX}" --icon "${CMAKE_SOURCE_DIR}/Dependent.svg"  --name ${_app_name} --target ${_app_name} --fullname ${_app_fullname}  --comment ${_app_comment}
  DEPENDS ${_app_name}
  VERBATIM
  USES_TERMINAL
  SOURCES ${CMAKE_SOURCE_DIR}/Dependent.svg
  )
else()
  install(CODE [[
	]])
endif()

# include(CPack)
