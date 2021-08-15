#include "MLIMainWindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QAction>
#include <QDebug>

MLIMainWindow::MLIMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , imageLabel(new QLabel)
    , scrollArea(new QScrollArea)
{
    ui->setupUi(this);

    // see https://doc.qt.io/qt-5/qtwidgets-widgets-imageviewer-example.html
    imageLabel->setBackgroundRole(QPalette::Base);
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);

    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(imageLabel);
    // scrollArea->setVisible(false);

    ui->splitter->addWidget(scrollArea);

    connect(ui->actionQuit, &QAction::triggered, this, &MLIMainWindow::OnFileClose);
    connect(ui->actionOpen, &QAction::triggered, this, &MLIMainWindow::OnFileOpen);
}

MLIMainWindow::~MLIMainWindow()
{
    delete ui;
}

void MLIMainWindow::OnFileOpen()
{
#ifdef Q_OS_ASM
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
#else

    QString fileName = QFileDialog::getOpenFileName(this,
          tr("Open Address Book"), "",
          tr("Address Book (*.png);;All Files (*)"));
    qDebug() << QString("fileName = %1").arg(fileName);
#ifdef SIMPLE_HANDLING
    ui->imageLabel->setPixmap(QPixmap(fileName));
    ui->imageLabel->adjustSize();
#else
    QPixmap pixmap(fileName);
    if (!pixmap.isNull())
    {
#ifdef CREATOR_QLABEL
        qDebug() << QString("pixmap = %1 %2").arg(pixmap.width()).arg(pixmap.height());
        qDebug() << QString("ui->imageLabel = %1 %2").arg(ui->imageLabel->width()).arg(ui->imageLabel->height());
        qDebug() << QString("ui->scrollAreaWidgetContents = %1 %2").arg(ui->scrollAreaWidgetContents->width()).arg(ui->scrollAreaWidgetContents->height());

        int w = std::min(pixmap.width(),  ui->scrollAreaWidgetContents->width());
        int h = std::min(pixmap.height(), ui->scrollAreaWidgetContents->height());
        pixmap = pixmap.scaled(QSize(w, h), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        ui->imageLabel->setPixmap(pixmap);
        ui->imageLabel->adjustSize();
#else
        qDebug() << QString("pixmap = %1 %2").arg(pixmap.width()).arg(pixmap.height());
        qDebug() << QString("imageLabel = %1 %2").arg(imageLabel->width()).arg(imageLabel->height());
        qDebug() << QString("scrollArea = %1 %2").arg(scrollArea->width()).arg(scrollArea->height());

        int w = std::min(pixmap.width(),  scrollArea->width());
        int h = std::min(pixmap.height(), scrollArea->height());
        pixmap = pixmap.scaled(QSize(w, h), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        imageLabel->setPixmap(pixmap);
        imageLabel->adjustSize();
#endif
    }

#endif
#endif
}

void MLIMainWindow::OnFileClose()
{
    this->close();
}
