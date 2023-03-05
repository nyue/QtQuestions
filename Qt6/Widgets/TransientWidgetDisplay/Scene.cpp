#include "Scene.h"

#include <cassert>

#include <QFont>
#include <QFontMetrics>

Scene::Scene(QObject *parent)
:_panel(0) {

}

void Scene::updateScene() {

}

Node* Scene::addNode() {
	Node* nodePtr = nullptr;
	if (_panel) {
		QFont f = this->property("font").value<QFont>();
		QFontMetrics fm(f);
		char nodeName[1024];
		int sResult = sprintf(nodeName, "Node%04lu", _nodes.size());
		assert(sResult >= 0);
		nlohmann::json attributes;
		nodePtr = new Node(nodeName, attributes, _panel);
		this->addItem(nodePtr);
		std::pair<NodeContainer::iterator, bool> iResult = _nodes.insert(NodeContainer::value_type(nodeName, nodePtr));
		assert(iResult.second);
	}
	return nodePtr;

}

void Scene::setPanel(QHBoxLayout* panel) {
	_panel = panel;
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
	QGraphicsScene::mousePressEvent(event);
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
	QGraphicsScene::mouseReleaseEvent(event);
}
