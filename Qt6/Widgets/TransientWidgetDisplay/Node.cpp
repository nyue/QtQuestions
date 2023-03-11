#include "Node.h"
#include "Utils.h"

#include <QPainter>
#include <QPointF>
#include <QRectF>
#include <QVBoxLayout>
#include <QLabel>
#include <QString>
#include <QDebug>
#include <QList>
#include <QSlider>

#include <iostream>

#include <boost/format.hpp>

Node::Node(const std::string& name,
		 const nlohmann::json& attributes,
         const QFontMetrics *fontMetrics,
		 QGraphicsItem *parent)
:QGraphicsItem(parent)
,_width(nodeWidth)
,_height(nodeHeight)
,_radius(nodeRadius)
,_name(name)
,_fontMetrics(fontMetrics)
{
	_pen.setWidth(1.0);
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);

}

Node::Node(const std::string &name,
		   const nlohmann::json& attributes,
           const QFontMetrics *fontMetrics,
		   QVBoxLayout* panel,
		   QGraphicsItem *parent)
:QGraphicsItem(parent)
,_panel(panel)
,_width(nodeWidth)
,_height(nodeHeight)
,_radius(nodeRadius)
,_name(name)
,_fontMetrics(fontMetrics)
,_ui(new QWidget())
{
	_ui->setObjectName(QString(name.c_str())+QString("_ui"));

	std::cout << "Node::Node()" << std::endl;
	_pen.setWidth(1.0);

    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    // setZValue(NodeZ);

    {
    	// Minimally, add a label so we know which node this UI belongs to when
    	// it is being shown
    	_ui->setLayout(new QVBoxLayout());
    	_ui->layout()->setAlignment(Qt::AlignTop|Qt::AlignLeft);
    	_ui->layout()->addWidget(new QLabel(name.c_str()));


    	// Setup
        float attributeDeltaY = attributeHeight * 1.5;
        float attributeStartY = attributeDeltaY;
        size_t index = 0;  // shared by both in and out attribute so their labels don't clash
        size_t total_attribute_count = 0;

    	// Build attributes UI if required (we only build UI for input
    	// attributes
    	// if (!attributes.is_null()) {
		if (attributes.contains("in")) {
			nlohmann::json in_attributes = attributes["in"];
			total_attribute_count += in_attributes.size();
			std::cout << boost::format("in_attributes.size() = %1%") % in_attributes.size() << std::endl;
		    for (nlohmann::json::iterator in_attr = in_attributes.begin(); in_attr != in_attributes.end(); ++in_attr) {
				float y = attributeStartY + index * attributeDeltaY;
				std::string key = in_attr.key();
				std::string type = in_attr.value()["type"];

				Attribute *attr = new Attribute(key, true, attributeWidth, y, type, _fontMetrics, _ui, this);
				_in_sockets.insert(AttributeContainer::value_type(key,attr));
		    	_ui->layout()->addWidget(attr->widget());

				index++;
		    }
		}

		if (attributes.contains("out")) {
			nlohmann::json out_attributes = attributes["out"];
			total_attribute_count += out_attributes.size();

		}

        _height = attributeDeltaY * (total_attribute_count+1);

    }
}

Node::~Node() {
	std::cout << "Node::~Node() destructor" << std::endl;
}

int Node::type() const {
	return Type;
}

QRectF Node::boundingRect() const {
	// std::cout << "Node::boundingRect()" << std::endl;
    return QRectF(0,0,_width,_height);
}

void Node::paint(QPainter *painter,
				 const QStyleOptionGraphicsItem *option,
				 QWidget *widget) {
    painter->setPen(_pen);

    painter->drawRoundedRect(0, 0,
                            _width,
                            _height,
                            _radius,
                            _radius);
}

void Node::mousePressEvent(QGraphicsSceneMouseEvent *event) {
#ifdef OLD_APPROACH
	if (_panel->count()==0) {
		// qDebug() << "Node::mousePressEvent count == 0 [add]";
		_panel->addWidget(_ui);
	} else {
		// replace
		// qDebug() << "Node::mousePressEvent count != 0 [replace]";
		QWidget *pExistingWidget = _panel->itemAt(0)->widget();
		if (pExistingWidget != _ui) {
			// Only if not the same widget
			_panel->replaceWidget(pExistingWidget, _ui);
			// std::cout << boost::format("replace pExistingWidget=%p _ui=%p") % pExistingWidget % &_ui << std::endl;
			pExistingWidget->setParent(nullptr); // Important, otherwise it still shows up
		}
	}
#else // OLD_APPROACH
#endif // OLD_APPROACH

    QGraphicsItem::mousePressEvent(event);
}

void Node::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    // reinterpret_cast<NovScene*>(scene())->updateScene();
    QGraphicsItem::mouseMoveEvent(event);

}

void Node::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
	// qDebug() << "Node::mouseReleaseEvent";
    QGraphicsItem::mouseReleaseEvent(event);
}
