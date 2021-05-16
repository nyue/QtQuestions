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
	// The recommend way to open file when using it in WASM
	// https://doc.qt.io/qt-5/qfiledialog.html#getOpenFileContent
    auto fileContentReady = [](const QString &fileName, const QByteArray &fileContent) {
        if (fileName.isEmpty()) {
            // No file was selected
        } else {
            // Use fileName and fileContent
        }
    };
    QFileDialog::getOpenFileContent("Images (*.png *.xpm *.jpg)",  fileContentReady);
}

void IOMainWindow::OnFileClose()
{
    this->close();
}
