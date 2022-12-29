# http://zetcode.com/gui/qt5/menusandtoolbars/
cmake_minimum_required(VERSION 3.25)

# appdir_init --root=$HOME/temp/CMakeAppDir --name=Play --icon=/home/nyue/Pictures/Bethelsight_ca_QR_code.svg --exe=/data2/nyue/projects/Qt/questions/QtQuestions_git/Qt5/deployqt/simple_app_using_cmake/build/Play --fullname="CMake Special Application" --comment="CMake Special comments"
#
# env LD_LIBRARY_PATH=/home/nyue/systems/Qt/5.14.2/5.14.2/gcc_64/lib:$LD_LIBRARY_PATH PATH=$HOME/systems/Qt/5.14.2/5.14.2/gcc_64/bin:$PATH ~/Downloads/linuxdeployqt-continuous-x86_64.AppImage /home/nyue/temp/CMakeAppDir/usr/share/applications/Play.desktop -appimage
#
project(PlayApplication)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON )
set(CMAKE_AUTOUIC ON )

find_package(Qt5 COMPONENTS Core Gui Widgets
  REQUIRED CONFIG)

add_executable(Play
  main.cpp
  anothermenu.cpp
  )

target_link_libraries(Play
  Qt5::Core
  Qt5::Gui
  Qt5::Widgets)
  
# QT5_USE_MODULES ( AnotherMenu Core Gui Widgets)

