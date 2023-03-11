#include "Node.h"

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

Node::Node(const std::string &name,
		   /* later
		   const nlohmann::json& attributes,
           const QFontMetrics *fontMetrics,
		   QVBoxLayout* panel,
		   */
		   QGraphicsItem *parent)
	:QGraphicsItem(parent)
	,_name(name)
	,_width(nodeWidth)
	,_height(nodeHeight)
	,_radius(nodeRadius)
	 /* later
		,_panel(panel)
		,_fontMetrics(fontMetrics)
		,_ui(new QWidget())
	 */
{
	std::cout << "Node::Node()" << std::endl;
	_pen.setWidth(1.0);
	
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
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
