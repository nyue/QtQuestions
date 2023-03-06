#include "Attribute.h"
#include "constants.h"

#include <boost/format.hpp>
#include <iostream>

Attribute::Attribute(const std::string &name,
		 	 	 	 bool labelOnRight,
					 float x, float y,
					 const std::string &type,
  			         const QFontMetrics *fontMetrics,
					 QGraphicsItem *parent)
:QGraphicsItem(parent)
,_width(attributeWidth)
,_height(attributeHeight)
,_radius(attributeRadius)
,_labelOnRight(labelOnRight)
,_label(name)
,_type(type)
,_fontMetrics(fontMetrics)
{
	// Do these before setPos() as the calculations will be off
    QRectF tightRect = fontMetrics->tightBoundingRect(name.c_str());
    _labelRect = mapToParent(tightRect).boundingRect();

    _pen.setWidth(1);
    std::cout << boost::format("setPos(%1%,%2%)") % x % y << std::endl;

    // Try to do this last as it affects other calculations
    setPos(x, y);
}

Attribute::~Attribute() {

}

QRectF Attribute::boundingRect() const {
    return QRectF(0, 0, _width, _height);
}

void Attribute::paint(QPainter *painter,
					  const QStyleOptionGraphicsItem *option,
					  QWidget *widget) {
    painter->setPen(_pen);
    painter->drawPath(getPainterPath());
    painter->drawText(_labelRect, _label.c_str());
}

QPainterPath Attribute::getPainterPath() const {
    QPainterPath path;

    path.addEllipse(_width/4,0,_width/2,_height);
    return path;

}
