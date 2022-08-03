add_executable(bounding_volume
  main.cpp
  )

target_link_libraries(bounding_volume
  Qt6::Widgets
  Qt6::3DCore
  Qt6::3DRender
  Qt6::3DExtras
  )
