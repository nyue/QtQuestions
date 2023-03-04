#include "Node.h"

#include <QPainter>
#include <QPointF>
#include <QRectF>

#include <iostream>

Node::Node(const std::string &name,
		   const nlohmann::json& attributes,
		   QGraphicsItem *parent)
	:QGraphicsItem(parent)
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

}

Node::~Node() {

}

int Node::type() const {
	return Type;
}

QRectF Node::boundingRect() const {
	std::cout << "Node::boundingRect()" << std::endl;
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
    QGraphicsItem::mousePressEvent(event);
}

void Node::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    // reinterpret_cast<NovScene*>(scene())->updateScene();
    QGraphicsItem::mouseMoveEvent(event);

}

void Node::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    QGraphicsItem::mouseReleaseEvent(event);

}
