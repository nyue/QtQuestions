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
#include <QVBoxLayout>

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
    	_panel = new QVBoxLayout(_scrollAreaWidgetContents);
    	_panel->setObjectName("scrollAreaHBoxLayout");
    	// _panel->setContentsMargins(QMargins(0, 0, 0, 0));
		_panel->setAlignment(Qt::AlignTop|Qt::AlignLeft);

    	// pScrollArea->setLayout(_panel);

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
	QVBoxLayout *pHBLayout = findChild<QVBoxLayout *>("scrollAreaHBoxLayout");
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
#ifdef OLD_APPROACH
        	Node* nptr = sptr->addNodeOld();
#else // OLD_APPROACH
        	sptr->addNode();
#endif // OLD_APPROACH
    	}
    }
#endif // DIRECT_PANEL
}

void AppMainWindow::OnReplace() {
    qDebug() << "AppMainWindow::OnReplace() 0100";
    QVBoxLayout *pHBLayout = findChild<QVBoxLayout *>("scrollAreaHBoxLayout");
	if (pHBLayout) {
		QPushButton *pButton = new QPushButton("Replace Button", this);

		QPushButton *pAddButton = findChild<QPushButton *>("addButton");
		if (pAddButton && pButton) {
			pHBLayout->replaceWidget(pAddButton, pButton);
		}
	}
}
