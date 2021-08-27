set(CMAKE_INCLUDE_CURRENT_DIR ON)

qt5_wrap_ui(ui_headers
  ugi.ui
  )

qt5_wrap_cpp(moc_srcs
  UGIGraphicsScene.h
  UGIGraphicsView.h
  UGIMainWindow.h
  )

add_executable ( ugi
  ${moc_srcs}
  ${ui_headers}
  main.cpp
  UGIAddEllipseCommand.cpp
  UGIGraphicsScene.cpp
  UGIGraphicsView.cpp
  UGIMainWindow.cpp
  )

target_link_libraries( ugi
  Qt5::Gui
  Qt5::Core
  Qt5::Network
  Qt5::Widgets
  )
