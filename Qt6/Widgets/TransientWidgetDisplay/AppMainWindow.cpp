#include "AppMainWindow.h"

#include <QApplication>
#include <QWidget>
#include <QFileDialog>
#include <QString>
#include <QWidget>
#include <QDebug>
#include <QPushButton>
#include <QSplitter>
#include <QLabel>
#include <QScrollArea>
#include <QHBoxLayout>

#include <iostream>

AppMainWindow::AppMainWindow(QWidget *parent)
: QMainWindow(parent)
, ui(new Ui::MainWindow)
{
        // qDebug() << "AppMainWindow BEFORE";
        ui->setupUi(this);
        connect(ui->actionQuit, &QAction::triggered, this, &QApplication::quit);
        connect(ui->actionAdd, &QAction::triggered, this, &AppMainWindow::OnAdd);
        connect(ui->actionReplace, &QAction::triggered, this, &AppMainWindow::OnReplace);
        _scrollAreaWidgetContents = findChild<QWidget *>("scrollAreaWidgetContents");

        //
    	QScrollArea *pScrollArea = findChild<QScrollArea *>("scrollArea");
    	QHBoxLayout *pScrollAreaHBoxLayout = new QHBoxLayout();
    	pScrollAreaHBoxLayout->setObjectName("scrollAreaHBoxLayout");
    	pScrollArea->setLayout(pScrollAreaHBoxLayout);

}

AppMainWindow::~AppMainWindow() {
        delete ui;
}

void AppMainWindow::OnAdd() {
	QHBoxLayout *pHBLayout = findChild<QHBoxLayout *>("scrollAreaHBoxLayout");
	if (pHBLayout) {
		QPushButton *pButton = new QPushButton("Add Button", this);
		pButton->setObjectName("addButton");
		qDebug() << "AppMainWindow::OnAdd() 0100";
		pHBLayout->addWidget(pButton);
		// repaint();
		//  update();
	}
}

void AppMainWindow::OnReplace() {
    qDebug() << "AppMainWindow::OnReplace() 0100";
	QHBoxLayout *pHBLayout = findChild<QHBoxLayout *>("scrollAreaHBoxLayout");
	if (pHBLayout) {
		QPushButton *pButton = new QPushButton("Replace Button", this);

		QPushButton *pAddButton = findChild<QPushButton *>("addButton");
		if (pAddButton && pButton) {
			pHBLayout->replaceWidget(pAddButton, pButton);
		}
	}
}
