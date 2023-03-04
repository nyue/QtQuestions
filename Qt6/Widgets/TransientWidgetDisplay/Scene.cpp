#include "Scene.h"
#include "Node.h"

#include <cassert>

#include <QFont>
#include <QFontMetrics>

Scene::Scene(QObject *parent) {

}

void Scene::updateScene() {

}

void Scene::addNode() {
	QFont f = this->property("font").value<QFont>();
	QFontMetrics fm(f);
	char nodeName[1024];
	int sResult = sprintf(nodeName, "Node%04lu", _nodes.size());
	assert(sResult >= 0);
	nlohmann::json attributes;
	Node* nodePtr = new Node(nodeName, attributes);
	this->addItem(nodePtr);
	std::pair<NodeContainer::iterator, bool> iResult = _nodes.insert(NodeContainer::value_type(nodeName, nodePtr));
	assert(iResult.second);
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
	QGraphicsScene::mousePressEvent(event);
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
	QGraphicsScene::mouseReleaseEvent(event);
}
