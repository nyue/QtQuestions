#include "AppMainWindow.h"

#include <QApplication>
#include <QWidget>

AppMainWindow::AppMainWindow(QWidget *parent)
: QMainWindow(parent)
, ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	connect(ui->actionQuit, &QAction::triggered, this, &QApplication::quit);
	connect(ui->actionPopulate, &QAction::triggered, this, &AppMainWindow::OnPopulate);
}

AppMainWindow::~AppMainWindow()
{
	delete ui;
}

void AppMainWindow::OnPopulate()
{
	printf("POPULATE\n");
	ui->graphicsView->populate();
}
