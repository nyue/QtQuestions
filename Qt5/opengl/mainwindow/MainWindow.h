#pragma once

#include <QMainWindow>
#include <QCheckBox>
#include <QLabel>
#include <QComboBox>
#include <QTranslator>
#include <QCoreApplication>
#include <QSharedPointer>
#include <QVector>
#include "MyOpenGLWidget.h"

class MainWindow : public QMainWindow
{
    // NOTICE THIS MACRO
    Q_OBJECT
    //
public:
    MainWindow(QWidget *parent = 0);
private:
    MyOpenGLWidget* ui_openglWidget;
};
