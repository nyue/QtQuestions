#include "CountryGraphicsView.h"

#include <QContextMenuEvent>
#include <QDebug>

CountryGraphicsView::CountryGraphicsView(QWidget *parent)
    : QGraphicsView(parent)
{
}

CountryGraphicsView::~CountryGraphicsView()
{

}

void CountryGraphicsView::contextMenuEvent(QContextMenuEvent *event)
{
	qDebug() << "CountryGraphicsView::contextMenuEvent";
}
