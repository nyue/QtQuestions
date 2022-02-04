#include "MyMainWindow.h"
#include <iostream>
#include <boost/format.hpp>
//
#include <QFileDialog>
#include <QApplication>

MyMainWindow::MyMainWindow(QWidget *parent)
    : QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);

    connect(ui->actionQuit, &QAction::triggered, this, &QApplication::quit);
}

MyMainWindow::~MyMainWindow()
{
    delete ui;
}

