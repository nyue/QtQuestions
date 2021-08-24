#include "UGIMainWindow.h"
#include "ui_ugi.h"
#include <QFileDialog>
#include <QAction>
#include <QDebug>

UGIMainWindow::UGIMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new UGIGraphicsScene(this);
    undoStack = new QUndoStack(this);

    connect(ui->actionQuit, &QAction::triggered, this, &UGIMainWindow::OnFileClose);

    ui->graphicsView->setScene(scene);
}

UGIMainWindow::~UGIMainWindow()
{
    delete ui;
}

void UGIMainWindow::OnFileClose()
{
    this->close();
}
