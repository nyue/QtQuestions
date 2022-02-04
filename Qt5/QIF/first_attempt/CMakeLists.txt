add_library(ms SHARED
  MyShared.cpp
  )

add_executable(qif_first_attempt
  main.cpp
  MyMainWindow.cpp
  )

target_link_libraries(qif_first_attempt PRIVATE
  Qt5::Core
  Qt5::Widgets
  )