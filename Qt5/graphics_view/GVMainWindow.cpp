#include "GVMainWindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QAction>
#include <QDebug>

GVMainWindow::GVMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionQuit, &QAction::triggered, this, &GVMainWindow::OnFileClose);
    connect(ui->actionSave, &QAction::triggered, this, &GVMainWindow::OnFileSave);
    connect(ui->actionOpen, &QAction::triggered, this, &GVMainWindow::OnFileOpen);
#ifdef Q_OS_WASM
    ui->actionSave->setText(tr("Download"));
    ui->menuFile->removeAction(ui->actionSave_As);
#endif
}

GVMainWindow::~GVMainWindow()
{
    delete ui;
}

void GVMainWindow::OnFileOpen()
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

void GVMainWindow::OnFileSave()
{
    QByteArray imageData; // obtained from e.g. QImage::save()
    QFileDialog::saveFileContent(imageData
                                 //, "myimage.png"
                                 );
}

void GVMainWindow::OnFileClose()
{
    this->close();
}
