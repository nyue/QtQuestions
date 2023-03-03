#include "AppMainWindow.h"

#include <QApplication>
#include <QWidget>
#include <QFileDialog>
#include <QString>
#include <QDebug>

#include <iostream>

AppMainWindow::AppMainWindow(QWidget *parent)
: QMainWindow(parent)
, ui(new Ui::MainWindow)
{
        // qDebug() << "AppMainWindow BEFORE";
        ui->setupUi(this);
        connect(ui->actionQuit, &QAction::triggered, this, &QApplication::quit);
}

AppMainWindow::~AppMainWindow()
{
        delete ui;
}
