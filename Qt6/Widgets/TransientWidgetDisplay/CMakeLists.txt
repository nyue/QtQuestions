add_executable(twd
  main.cpp
  AppMainWindow.cpp
  Node.cpp
  Attribute.cpp
  Scene.cpp
  View.cpp
  Utils.cpp
  )

target_link_libraries(twd PRIVATE
  ${q_link_libraries}
  )

qt_finalize_executable(twd)
