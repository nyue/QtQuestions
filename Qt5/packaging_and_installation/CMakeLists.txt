add_executable(package_install
  MyMainWindow.cpp
  main.cpp
  )

set(REQUIRED_LIBS
  Qt5::Core
  Qt5::Widgets
  )
message("REQUIRED_LIBS = ${REQUIRED_LIBS}")

target_link_libraries(package_install PRIVATE
  ${REQUIRED_LIBS}
  )

install(TARGETS package_install
  BUNDLE DESTINATION . COMPONENT Runtime
  RUNTIME DESTINATION bin COMPONENT Runtime
  )

foreach(LIB ${REQUIRED_LIBS})
  if(LIB MATCHES "Qt5::")
    get_target_property(LIB ${LIB} LOCATION_${CMAKE_BUILD_TYPE})
	message("LIB = ${LIB}")
	list(APPEND QTLIBS ${LIB})
  endif()
  get_filename_component(LIB_DIR ${LIB} DIRECTORY)
  if(LIB_DIR MATCHES ".*framework$") #Only match paths ending in .framework
    get_filename_component(LIB_DIR ${LIB_DIR} DIRECTORY) #get parent dir
  endif()
  set(LIB_DIRS ${LIB_DIRS}
    ${LIB_DIR}
    )
endforeach()
message("LIB_DIRS ${LIB_DIRS}")
message("QTLIBS ${QTLIBS}")

set(APPS $<TARGET_FILE:package_install>)  # paths to executables
set(QTDIRS "/home/nyue/systems/Qt/5.14.2/5.14.2/gcc_64/lib/libQt5Core.so")
set(DIRS ${LIB_DIRS})

install(CODE
  "
    include(BundleUtilities)
    copy_and_fixup_bundle(${APPS} ${CMAKE_INSTALL_PREFIX}/bin/package_install \"\" \"${DIRS}\")
  "
  COMPONENT Runtime)
