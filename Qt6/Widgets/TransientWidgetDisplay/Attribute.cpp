#include "Attribute.h"
// #include "Utils.h"
#include "constants.h"

#include <boost/format.hpp>
#include <iostream>

#include <QSlider>
#include <QString>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>

Attribute::Attribute(const std::string &name,
		 	 	 	 bool labelOnRight,
					 float x, float y,
					 const std::string &type,
  			         const QFontMetrics *fontMetrics,
				     QWidget *widgetParent,
					 QGraphicsItem *parent)
:QGraphicsItem(parent)
,_width(attributeWidth)
,_height(attributeHeight)
,_radius(attributeRadius)
,_labelOnRight(labelOnRight)
,_label(name)
,_type(type)
,_fontMetrics(fontMetrics)
,_widget(new QWidget(widgetParent))
{
	_widget->setObjectName(QString(name.c_str())+QString("_widget"));
	// Set up the associated UI widget here so we can connect
	// up the action stuff at the same time
	if (_type.compare("string")==0) {
		createLineEditWidget(_label.c_str(), _widget);
	} else if (_type.compare("int")==0) {
		Range range;
		range.first.setValue<int>(0);
		range.second.setValue<int>(10);
		 createSliderWidget(_label.c_str(),&range,_widget);

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
	if (_widget) {
		if (!_widget->parentWidget()) {
			std::cout << "Attribute::~Attribute() destructor" << std::endl;
			delete _widget;
		} else {
			std::cout << boost::format("Attribute::~Attribute() destructor : parent '%1%'") %
					_widget->parentWidget()->objectName().toStdString() << std::endl;
		}

	}
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
	// printf("updateValue(%d)\n",value);
}

void Attribute::createLineEditWidget(const QString& name, QWidget* parent) {
	QHBoxLayout *hbox = new QHBoxLayout(parent);
	parent->setLayout(hbox);
	hbox->addWidget(new QLabel(name, parent));
	hbox->addWidget(new QLineEdit(parent));

}

void Attribute::createSliderWidget(const QString& name, const Range* range, QWidget* parent) {
	QHBoxLayout *hbox = new QHBoxLayout(parent);
	parent->setLayout(hbox);
	hbox->addWidget(new QLabel(name, parent));
	hbox->addWidget(new QLineEdit(parent));
	QSlider* slider = new QSlider(Qt::Horizontal, parent);
	if (range)
		slider->setRange(range->first.toInt(), range->second.toInt());
	hbox->addWidget(slider);
}
