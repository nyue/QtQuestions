add_executable(package_install
  MyMainWindow.cpp
  main.cpp
  )

target_link_libraries(package_install PRIVATE
  Qt5::Core
  Qt5::Widgets
  )
