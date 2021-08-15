QT += widgets svg

SOURCES += main.cpp
build_all:!build_pass {
    CONFIG -= build_all
    CONFIG += release
}
