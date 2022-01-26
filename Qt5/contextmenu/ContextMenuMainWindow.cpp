#include "ContextMenuMainWindow.h"

ContextMenuMainWindow::ContextMenuMainWindow(QWidget *parent)
    : QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);

    connect(ui->actionQuit, &QAction::triggered, this, &QApplication::quit);
}

ContextMenuMainWindow::~ContextMenuMainWindow()
{
    delete ui;
}
