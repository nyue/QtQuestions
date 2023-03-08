#include "Scene.h"
#include "Node.h"

#include <cassert>
#include <iostream>

#include <QFont>
#include <QFontMetrics>

#include <boost/format.hpp>

Scene::Scene(QObject *parent)
:_panel(0) {
	_fontMetrics = new QFontMetrics(property("font").value<QFont>());
}

Scene::~Scene() {
	delete _fontMetrics;
}

void Scene::updateScene() {
}

Node* Scene::addNode() {
	Node* nodePtr = nullptr;
	if (_panel) {
		/*
		QFont f = this->property("font").value<QFont>();
		QFontMetrics fm(f);
		*/
		char nodeName[1024];
		int sResult = sprintf(nodeName, "Node%04lu", _nodes.size());
		assert(sResult >= 0);
		nlohmann::json attributes;
		nlohmann::json in_attributes;
		in_attributes["command"] = {
				{"type","string"},
				{"value",""},
				{"range",nullptr}
		};
		in_attributes["stdin"] = {
				{"type","string"},
				{"value",""},
				{"range",nullptr}
		};
		in_attributes["sections"] = {
				{"type","int"},
				{"value",0},
				{"range",{0,5}}
		};
		/*
		const size_t num_extra_string_attributes = 32;
		const size_t num_extra_int_attributes = 3;
		for (auto i=0;i<num_extra_string_attributes;i++) {
			std::string attribute_name = (boost::format("sattr_%04d") % i).str();
			std::cout << boost::format("attribute_name = '%1%'") % attribute_name << std::endl;
			in_attributes[attribute_name] = {
					{"type","string"},
					{"value",""},
					{"range",nullptr}
			};
		}
		*/
		/*
		in_attributes["angle"] = {
				{"type","real"},
				{"value",0.0},
				{"range",{0.0,360.0}}
		};
		*/
		nlohmann::json out_attributes = {};
		attributes["in"] = in_attributes;
		attributes["out"] = out_attributes;
		std::pair<NodeContainer::iterator, bool> iResult = _nodes.insert(NodeContainer::value_type(nodeName, NodeShdPtr()));
		if (iResult.second) {
			iResult.first->second.reset(new Node(nodeName, attributes, _fontMetrics, _panel));
			assert(iResult.second);
			nodePtr = iResult.first->second.get();
			this->addItem(nodePtr);
		}
	}
	return nodePtr;

}

void Scene::setPanel(QVBoxLayout* panel) {
	_panel = panel;
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
	QGraphicsScene::mousePressEvent(event);
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
	QGraphicsScene::mouseReleaseEvent(event);
}
