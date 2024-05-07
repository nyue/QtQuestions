cmake_minimum_required(VERSION 3.25)

project(Qt6Questions)

option(USE_QT5    "Use Qt5 instead"            OFF)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Boost REQUIRED)
find_package(nlohmann_json REQUIRED)
if (USE_QT5)
  find_package (Qt5
	COMPONENTS Widgets
	REQUIRED)
  set(q_link_libraries
	Qt5::Widgets
	nlohmann_json::nlohmann_json
	Boost::headers
	)
else(USE_QT5)
  find_package (Qt6
	COMPONENTS Widgets Gui Core
	REQUIRED)
  set(q_link_libraries
	Qt6::Widgets
	Qt6::Gui
	Qt6::Core
	nlohmann_json::nlohmann_json
	Boost::headers
	)
endif(USE_QT5)

# add_subdirectory(3D)
add_subdirectory(Widgets)
add_subdirectory(UndoFramework)
