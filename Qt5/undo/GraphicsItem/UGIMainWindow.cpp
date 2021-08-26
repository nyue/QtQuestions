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
    connect(ui->actionUndo, &QAction::triggered, this, &UGIMainWindow::OnUndo);
    connect(ui->actionRedo, &QAction::triggered, this, &UGIMainWindow::OnRedo);

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

void UGIMainWindow::OnUndo()
{
    qDebug() << "UGIMainWindow::OnUndo";
    undoStack->undo();
}

void UGIMainWindow::OnRedo()
{
    qDebug() << "UGIMainWindow::OnRedo";
    undoStack->redo();
}
