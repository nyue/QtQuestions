#include "MainWindow.h"
#include <QVBoxLayout>
#include <QDebug>
#include <QUiLoader>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	QUiLoader loader;
	QFile file(":/designer/mainwindow.ui");
    if (file.open(QFile::ReadOnly))
    {
        QWidget *mainwindow = loader.load(&file, this);
        // loader.setLanguageChangeEnabled(true);
        file.close();

        if (mainwindow) {
            ui_checkBox = findChild<QCheckBox*>("checkBox");
            Q_ASSERT(ui_checkBox);
            QObject::connect(ui_checkBox, SIGNAL(clicked()),  this, SLOT(doCheckBox()));

			//			setCentralWidget(mainwindow);
            
            QVBoxLayout *layout = new QVBoxLayout;
            layout->addWidget(mainwindow);
            setLayout(layout);
            


        }
    }
}


void MainWindow::doCheckBox() {
	qDebug() << "doCheckBox() called";
}

/*
void MainWindow::changeEvent(QEvent*)
{
}
*/
