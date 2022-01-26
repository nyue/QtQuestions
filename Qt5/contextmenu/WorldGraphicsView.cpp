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
	p2 = "world tomorrow";
	QAction* communications = _contextMenu->addAction("communications");
	connect(communications,  &QAction::triggered, this, [this, v1=p1, v2=p2]{ contextMenuHandler(v1,v2); });
}

WorldGraphicsView::~WorldGraphicsView()
{

}

void WorldGraphicsView::contextMenuEvent(QContextMenuEvent *event)
{
	qDebug() << "WorldGraphicsView::contextMenuEvent";
	_contextMenu->exec(event->globalPos());
}

void WorldGraphicsView::contextMenuHandler(const QString param1,const QString param2)
{
	qDebug() << param1;
	qDebug() << param2;
}
