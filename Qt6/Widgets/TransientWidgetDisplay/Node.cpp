#include "Node.h"

#include <QPainter>
#include <QPointF>
#include <QRectF>
#include <QHBoxLayout>
#include <QLabel>
#include <QString>
#include <QDebug>

#include <iostream>

Node::Node(const std::string &name,
		   const nlohmann::json& attributes,
		   QHBoxLayout* panel,
		   QGraphicsItem *parent)
	:QGraphicsItem(parent)
	,_panel(panel)
	,_width(nodeWidth)
	,_height(nodeHeight)
	,_radius(nodeRadius)
	,_name(name)
{

	std::cout << "Node::Node()" << std::endl;
	_pen.setWidth(1.0);

    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    // setZValue(NodeZ);

    {
    	// Minimally, add a label so we know which node this UI belongs to when
    	// it is being shown
    	_ui.setLayout(new QHBoxLayout());
    	_ui.layout()->addWidget(new QLabel(name.c_str()));

    	// Build attributes UI if required (we only build UI for input
    	// attributes
    	// if (!attributes.is_null()) {
    		if (attributes.contains("in")) {
    			nlohmann::json in_attributes = attributes["in"];
    		}
    	// }
    }
}

Node::~Node() {

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
	qDebug() << "Node::mousePressEvent";
	_panel->addWidget(&_ui);

    QGraphicsItem::mousePressEvent(event);
}

void Node::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    // reinterpret_cast<NovScene*>(scene())->updateScene();
    QGraphicsItem::mouseMoveEvent(event);

}

void Node::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
	qDebug() << "Node::mouseReleaseEvent";
    QGraphicsItem::mouseReleaseEvent(event);
}
