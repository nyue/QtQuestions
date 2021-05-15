#include "IOMainWindow.h"
#include "ui_mainwindow.h"

IOMainWindow::IOMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

IOMainWindow::~IOMainWindow()
{
    delete ui;
}
