#include "Attribute.h"
#include "Utils.h"
#include "constants.h"

#include <boost/format.hpp>
#include <iostream>

#include <QSlider>

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
,_widget(nullptr)
{
	// Set up the associated UI widget here so we can connect
	// up the action stuff at the same time
	if (_type.compare("string")==0) {
		_widget = attributeLineEditWidget(_label.c_str());
	} else if (_type.compare("int")==0) {
		Range range;
		range.first.setValue<int>(0);
		range.second.setValue<int>(10);
		_widget = attributeSliderWidget(_label.c_str(),&range);

		// Register action
		QSlider *slider = _widget->findChild<QSlider *>();
		slider->connect(slider, &QSlider::valueChanged,
	            [this](int intValue)
	            {
					updateValue(intValue);
	            });
	}

	// Do these before setPos() as the calculations will be off
    QRectF tightRect = fontMetrics->tightBoundingRect(name.c_str());
    _labelRect = mapToParent(tightRect).boundingRect();

    _pen.setWidth(1);

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

QWidget * Attribute::widget() {
	return _widget;
}

void Attribute::updateValue(int value) {
	printf("updateValue(%d)\n",value);
}
