QT   += core gui widgets svg
CONFIG += qt
CONFIG += c++11
CONFIG += lrelease
SOURCES += main.cpp
SOURCES += UGIMainWindow.cpp
SOURCES += UGIGraphicsView.cpp
SOURCES += UGIGraphicsScene.cpp
SOURCES += UGIAddEllipseCommand.cpp
HEADERS += UGIMainWindow.h
HEADERS += UGIGraphicsView.h
HEADERS += UGIGraphicsScene.h
HEADERS += UGIAddEllipseCommand.h
FORMS += ugi.ui
