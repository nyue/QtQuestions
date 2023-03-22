add_executable(package_install MACOSX_BUNDLE
  MyMainWindow.cpp
  main.cpp
  )

set(REQUIRED_LIBS
  Qt5::Widgets
  Qt5::Core
  )
message("REQUIRED_LIBS = ${REQUIRED_LIBS}")

target_link_libraries(package_install PRIVATE
  ${REQUIRED_LIBS}
  )

install(TARGETS package_install
  BUNDLE DESTINATION . COMPONENT Runtime
  RUNTIME DESTINATION . COMPONENT Runtime
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

if (WIN32)

  set(CMAKE_INSTALL_SYSTEM_RUNTIME_DESTINATION .)
  set(CMAKE_INSTALL_UCRT_LIBRARIES TRUE)
  include(InstallRequiredSystemLibraries)
  get_target_property(_qmake_executable Qt5::qmake IMPORTED_LOCATION)
  get_filename_component(_qt_bin_dir "${_qmake_executable}" DIRECTORY)
  find_program(WINDEPLOYQT_EXECUTABLE windeployqt HINTS "${_qt_bin_dir}")
  message("WINDEPLOYQT_EXECUTABLE ${WINDEPLOYQT_EXECUTABLE}")

  add_custom_command(TARGET package_install POST_BUILD
    COMMAND "${CMAKE_COMMAND}" -E remove_directory "${CMAKE_CURRENT_BINARY_DIR}/qtDeploy/"
    COMMAND "${CMAKE_COMMAND}" -E
    env PATH="${_qt_bin_dir}" "${WINDEPLOYQT_EXECUTABLE}"
    --verbose 0
    --no-compiler-runtime
    --no-angle
    --no-webkit2
    --no-quick-import
    --no-translations
    --dir "${CMAKE_CURRENT_BINARY_DIR}/qtDeploy/" $<TARGET_FILE:package_install>
    COMMENT "Deploying Qt..."
    )
  install(
    DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/qtDeploy/"
    DESTINATION .
    )
elseif (APPLE)
  # /Users/nyue/Qt5.14.2/5.14.2/clang_64/bin/macdeployqt /Users/nyue/projects/Qt/questions/build/packaging_and_installation/package_install.app -dmg
  message("HELLO WORLD")
  set(APPS $<TARGET_BUNDLE_DIR:package_install>)  # paths to executables
  # set(QTDIRS "/home/nyue/systems/Qt/5.14.2/5.14.2/gcc_64/lib/libQt5Core.so")
  set(DIRS ${LIB_DIRS})

  #    copy_and_fixup_bundle(/home/nyue/projects/Qt/QtQuestions/qt5_build/packaging_and_installation ${CMAKE_INSTALL_PREFIX} \"${QTLIBS}\" \"${QTLIBS}\")
  install(CODE
	"
    include(BundleUtilities)
    message(\"INSIDE APPS = ${APPS}\")
    message(\"INSIDE QTLIBS = ${QTLIBS}\")
    message(\"INSIDE DIRS = ${DIRS}\")
    fixup_bundle(\"${APPS}\" \"${QTLIBS}\" \"${DIRS}\")
  "
	COMPONENT Runtime)
else (WIN32)
endif(WIN32)
