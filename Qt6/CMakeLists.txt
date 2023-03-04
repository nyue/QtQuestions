cmake_minimum_required(VERSION 3.25)

project(Qt6Questions)

option(USE_QT5    "Use Qt5 instead"            OFF)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

if (USE_QT5)
  find_package (Qt5
	COMPONENTS Widgets
	REQUIRED)
  set(q_link_libraries
	Qt5::Widgets
	)
else(USE_QT5)
  find_package (Qt6
	COMPONENTS Widgets
	REQUIRED)
  set(q_link_libraries
	Qt6::Widgets
	)
endif(USE_QT5)

# add_subdirectory(3D)
add_subdirectory(Widgets)
