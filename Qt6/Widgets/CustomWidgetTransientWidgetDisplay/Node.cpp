#include "Node.h"
#include "Scene.h"
#include "ParametersWidget.h"

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
		   const nlohmann::json& attributes,
		   /* later
           const QFontMetrics *fontMetrics,
		   QVBoxLayout* panel,
		   */
		   QGraphicsItem *parent)
	:QGraphicsItem(parent)
	,_name(name)
	,_width(nodeWidth)
	,_height(nodeHeight)
	,_radius(nodeRadius)
	,_uiParent(new QWidget())
	 /* later
		,_panel(panel)
		,_fontMetrics(fontMetrics)
	 */
{
	std::cout << "Node::Node()" << std::endl;
	_pen.setWidth(1.0);
	
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
	
    _parameterUI = new ParametersWidget(name,
										attributes,
										this,
										_uiParent);
}

Node::~Node() {
	delete _uiParent;
}

int Node::type() const {
	return Type;
}

const std::string& Node::name() const {
	return _name;
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
	qDebug() << "Node::mousePressEvent()";
	QGraphicsItem::mousePressEvent(event);
}

void Node::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    // reinterpret_cast<NovScene*>(scene())->updateScene();
    QGraphicsItem::mouseMoveEvent(event);
}

void Node::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
	// qDebug() << "Node::mouseReleaseEvent";
	Scene *myScene = dynamic_cast<Scene *>(scene());
	if (myScene) {
		qDebug() << "Node::mouseReleaseEvent myScene";
		myScene->replaceParamaters(this);
	}
    QGraphicsItem::mouseReleaseEvent(event);
}

QWidget * Node::getUI() const {
	return _parameterUI;
}

void Node::returnUI(QWidget *ui) {
	ui->setParent(_uiParent);
}

void Node::onSliderValueChange(const QString& name, int value) {
	std::cout << boost::format("Node::onSliderValueChange : node = '%1%' name = '%2%', value = %3%") % _name % name.toStdString() % value << std::endl;
}
