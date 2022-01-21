#include "MyMainWindow.h"

#include <QApplication>
#include <QWidget>

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
