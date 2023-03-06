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

#include <iostream>

Node::Node(const std::string &name,
		   const nlohmann::json& attributes,
		   QVBoxLayout* panel,
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
    	_ui.setLayout(new QVBoxLayout());
    	_ui.layout()->setAlignment(Qt::AlignTop|Qt::AlignLeft);
    	_ui.layout()->addWidget(new QLabel(name.c_str()));


    	// Build attributes UI if required (we only build UI for input
    	// attributes
    	// if (!attributes.is_null()) {
		if (attributes.contains("in")) {
			nlohmann::json in_attributes = attributes["in"];
			for (nlohmann::json::iterator it = in_attributes.begin(); it != in_attributes.end(); ++it) {
				std::cout << it.key() << std::endl;
				std::cout << it.value()["type"] << std::endl;
				std::string type = it.value()["type"];
				if (type.compare("string")==0) {
			    	_ui.layout()->addWidget(attributeLineEditWidget(it.key().c_str()));
				} else if (type.compare("int")==0) {
					if (!it.value()["range"].is_null()) {
						Range range;
						range.first.setValue<int>(it.value()["range"][0]);
						range.second.setValue<int>(it.value()["range"][1]);
						_ui.layout()->addWidget(attributeSliderWidget(it.key().c_str(),&range));
					} else {
						_ui.layout()->addWidget(attributeSliderWidget(it.key().c_str()));
					}
				}
			}
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
	if (_panel->count()==0) {
		_panel->addWidget(&_ui);
	} else {
		// replace
		QWidget *pExistingWidget = _panel->itemAt(0)->widget();
		_panel->replaceWidget(pExistingWidget, &_ui);
		pExistingWidget->setParent(nullptr); // Important, otherwise it still shows up
	}

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
