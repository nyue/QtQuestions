add_executable(ca_app
  CircleGraphicsItem.cpp
  SquareGraphicsItem.cpp
  AbstractGraphicsItem.cpp
  MyGraphicsScene.cpp
  MyGraphicsView.cpp
  AppMainWindow.cpp
  main.cpp
  )

target_link_libraries(ca_app PRIVATE
  Qt5::Core
  Qt5::Widgets
  )
