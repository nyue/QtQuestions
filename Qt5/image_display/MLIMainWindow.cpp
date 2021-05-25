#include "MLIMainWindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QAction>
#include <QDebug>

MLIMainWindow::MLIMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionQuit, &QAction::triggered, this, &MLIMainWindow::OnFileClose);
    connect(ui->actionOpen, &QAction::triggered, this, &MLIMainWindow::OnFileOpen);
}

MLIMainWindow::~MLIMainWindow()
{
    delete ui;
}

void MLIMainWindow::OnFileOpen()
{
    // The recommend way to open file when using it in WASM
    // https://doc.qt.io/qt-5/qfiledialog.html#getOpenFileContent
    auto fileContentReady = [](const QString &fileName, const QByteArray & fileContent) {
        if (fileName.isEmpty()) {
            // No file was selected
        } else {
            qDebug() << QString("file name = %1").arg(fileName);
            qDebug() << QString("file content size = %1").arg(fileContent.size());
        }
    };
    QFileDialog::getOpenFileContent("Images (*.png *.xpm *.jpg)",  fileContentReady);
}

void MLIMainWindow::OnFileClose()
{
    this->close();
}
