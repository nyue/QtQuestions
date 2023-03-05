#include "AppMainWindow.h"

#include "View.h"
#include "Scene.h"

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
    	_panel = new QHBoxLayout();
    	_panel->setObjectName("scrollAreaHBoxLayout");
    	pScrollArea->setLayout(_panel);

    	// setup panel pointer in scene (so it can do add node with panel pointer
    	{
    	    View* vptr = this->findChild<View*>();
    	    if (vptr) {
    	    	qDebug() << "OnAdd() Found View";
    	    	Scene *sptr = dynamic_cast<Scene*>(vptr->scene());
    	    	sptr->setPanel(_panel);
    	    }
    	}
}

AppMainWindow::~AppMainWindow() {
        delete ui;
}

void AppMainWindow::OnAdd() {
#ifdef DIRECT_PANEL
	QHBoxLayout *pHBLayout = findChild<QHBoxLayout *>("scrollAreaHBoxLayout");
	if (pHBLayout) {
		QPushButton *pButton = new QPushButton("Add Button", this);
		pButton->setObjectName("addButton");
		qDebug() << "AppMainWindow::OnAdd() 0100";
		pHBLayout->addWidget(pButton);
	}
#else // DIRECT_PANEL
    View* vptr = this->findChild<View*>();
    if (vptr) {
    	qDebug() << "OnAdd() Found View";
    	Scene *sptr = dynamic_cast<Scene*>(vptr->scene());
    	if (sptr) {
        	qDebug() << "OnAdd() Castable Scene";
        	Node* nptr = sptr->addNode();
    	}
    }
#endif // DIRECT_PANEL
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
