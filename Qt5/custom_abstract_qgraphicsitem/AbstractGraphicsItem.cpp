#include "AbstractGraphicsItem.h"
#include <QPainter>

AbstractGraphicsItem::AbstractGraphicsItem(QGraphicsItem *parent)
{
	_bound.setWidth(50);
	_bound.setHeight(50);
}

void AbstractGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	painter->save();
	if (_shape.empty())
	{
		painter->drawLine(_bound.bottomLeft(),_bound.topRight());
		painter->drawLine(_bound.topLeft(),_bound.bottomRight());
	}
	else {
		if (_shape.compare("circle")==0)
		{
			painter->drawEllipse(_bound);
		}
		else if (_shape.compare("square")==0)
		{
			painter->drawRect(_bound);
		}
	}
	painter->restore();
}

QRectF AbstractGraphicsItem::boundingRect() const
{
	return _bound;
}
