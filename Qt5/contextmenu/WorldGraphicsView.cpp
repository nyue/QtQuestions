#include "WorldGraphicsView.h"

#include <QContextMenuEvent>
#include <QDebug>

WorldGraphicsView::WorldGraphicsView(QWidget *parent)
    : QGraphicsView(parent)
{
	_contextMenu = new QMenu(this);
	QString p1;
	QString p2;

	p1 = "hello";
	p2 = "world";
	QAction* communications = _contextMenu->addAction("communications",this,SLOT(contextMenuHandler(QString,QString)));
	p1 = "star";
	p2 = "war";
	QAction* transport = _contextMenu->addAction("transport",this,SLOT(contextMenuHandler(QString,QString)));
}

WorldGraphicsView::~WorldGraphicsView()
{

}

void WorldGraphicsView::contextMenuEvent(QContextMenuEvent *event)
{
	qDebug() << "WorldGraphicsView::contextMenuEvent";
	_contextMenu->exec(event->globalPos());
}

void WorldGraphicsView::contextMenuHandler(QString parameter1, QString parameter2)
{

}
