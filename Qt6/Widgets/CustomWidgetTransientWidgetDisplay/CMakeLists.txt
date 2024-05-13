add_executable(cwtwd
  main.cpp
  AppMainWindow.cpp
  AppMainWindow.h
  Attribute.cpp
  Attribute.h
  Node.cpp
  Node.h
  ParametersWidget.cpp
  ParametersWidget.h
  Scene.cpp
  Scene.h
  View.cpp
  View.h
  )

target_link_libraries(cwtwd PRIVATE
  ${q_link_libraries}
  )

qt_finalize_executable(cwtwd)
