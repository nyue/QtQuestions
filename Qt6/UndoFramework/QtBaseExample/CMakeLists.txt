add_executable(undoDemo
  commands.cpp
  diagramitem.cpp
  diagramscene.cpp
  main.cpp
  mainwindow.cpp
  )

target_link_libraries(undoDemo PRIVATE
  ${q_link_libraries}
  )

qt_finalize_executable(undoDemo)
