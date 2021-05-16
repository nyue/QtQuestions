#include "IOMainWindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QAction>

IOMainWindow::IOMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionQuit, &QAction::triggered, this, &IOMainWindow::OnFileClose);
    connect(ui->actionOpen, &QAction::triggered, this, &IOMainWindow::OnFileOpen);
}

IOMainWindow::~IOMainWindow()
{
    delete ui;
}

void IOMainWindow::OnFileOpen()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open Image"), "/tmp", tr("Image Files (*.png *.jpg *.bmp)"));
}

void IOMainWindow::OnFileClose()
{
    this->close();
}
