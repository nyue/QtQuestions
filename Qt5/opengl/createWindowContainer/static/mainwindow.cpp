#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_myWindow(new MyOpenGLWindow)
{
    ui->setupUi(this);

    m_myWindow->create();
    m_myWindow->setMainWindow(this);

    QWidget *w = QWidget::createWindowContainer(m_myWindow);

    takeCentralWidget();
    setCentralWidget(w);
}

MainWindow::~MainWindow()
{
    delete m_myWindow;
    delete ui;
}
