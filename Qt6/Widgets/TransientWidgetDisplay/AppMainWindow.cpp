#include "AppMainWindow.h"

#include <QApplication>
#include <QWidget>
#include <QFileDialog>
#include <QString>
#include <QWidget>
#include <QDebug>
#include <QPushButton>
#include <QSplitter>

#include <iostream>

AppMainWindow::AppMainWindow(QWidget *parent)
: QMainWindow(parent)
, ui(new Ui::MainWindow)
{
        // qDebug() << "AppMainWindow BEFORE";
        ui->setupUi(this);
        connect(ui->actionQuit, &QAction::triggered, this, &QApplication::quit);
        connect(ui->actionReplace, &QAction::triggered, this, &AppMainWindow::OnReplace);
        _scrollAreaWidgetContents = findChild<QWidget *>("scrollAreaWidgetContents");
}

AppMainWindow::~AppMainWindow() {
        delete ui;
}

void AppMainWindow::OnReplace() {
    qDebug() << "AppMainWindow::OnReplace() 0100";
	QPushButton *pButton = new QPushButton("My Button", this);
	if (pButton) {
		// pButton->show();
		pButton->resize(100,100);
	    qDebug() << "AppMainWindow::OnReplace() 0200";
	    QGridLayout *pLayout = findChild<QGridLayout *>("gridLayout");
	    if (pLayout) {
			qDebug() << "AppMainWindow::OnReplace() 0300";
			QWidget *pWidget = findChild<QWidget *>("scrollAreaWidgetContents");
			if (pWidget) {
				pLayout->replaceWidget(pWidget, pButton);
				// pButton->show();
				pWidget->show();
				pLayout->update();
			}
        }
	}
}
