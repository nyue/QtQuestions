#include "MainWindow.h"
#include <QVBoxLayout>
#include <QDebug>
#include <QUiLoader>
#include <QFile>
#include <QDir>
#include <QDirIterator>
#include <QWidget>
#include <QApplication>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QUiLoader loader;
    QFile file(":/designer/ogl.ui");
    file.open(QFile::ReadOnly);
    QWidget *widget = loader.load(&file, parent);
    loader.setTranslationEnabled(true);
    file.close();
    setCentralWidget(widget);

    // QOpenGLWidget *_ui_openglWidget = findChild<QOpenGLWidget*>("openGLWidget");
    ui_openglWidget = reinterpret_cast<MyOpenGLWidget*>(findChild<MyOpenGLWidget*>("openGLWidget"));
    // qDebug() << _ui_openglWidget;
    qDebug() << ui_openglWidget;
    ui_openglWidget->hello();
}
