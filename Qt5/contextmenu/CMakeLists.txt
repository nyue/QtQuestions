add_executable(cm WIN32
  CountryGraphicsView.cpp
  WorldGraphicsView.cpp
  ContextMenuMainWindow.cpp
  main.cpp
  )

target_link_libraries(cm PRIVATE
  Qt5::Core
  Qt5::Widgets
  )