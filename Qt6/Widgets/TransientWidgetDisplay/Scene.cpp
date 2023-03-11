#include "Scene.h"
#include "Node.h"

#include <cassert>
#include <iostream>

#include <QFont>
#include <QFontMetrics>
#include <QLabel>
#include <QLineEdit>
#include <QSlider>

#include <boost/format.hpp>

Scene::Scene(QObject *parent)
:_panel(0) {
	_fontMetrics = new QFontMetrics(property("font").value<QFont>());
}

Scene::~Scene() {
	std::cout << "Scene::~Scene() destructor" << std::endl;
	delete _fontMetrics;
}

void Scene::updateScene() {
}

#ifdef OLD_APPROACH
Node* Scene::addNodeOld() {
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
#else // OLD_APPROACH

void Scene::addNode() {
	char nodeName[1024];
	int sResult = sprintf(nodeName, "Node%04lu", _nodesAndUIs.size());
	nlohmann::json attributes;
	nlohmann::json in_attributes = {};
	nlohmann::json out_attributes = {};
	attributes["in"] = in_attributes;
	attributes["out"] = out_attributes;

	std::pair<NodeUIContainer::iterator, bool> iResult = _nodesAndUIs.insert(NodeUIContainer::value_type(nodeName, NodeUI()));
	if (iResult.second) {
		iResult.first->second._node.reset(new Node(nodeName, attributes, _fontMetrics));
		// iResult.first->second.reset(new Node(nodeName, attributes, _fontMetrics, _panel));
		addItem(iResult.first->second._node.get());
	}
}
#endif // OLD_APPROACH

void Scene::setPanel(QVBoxLayout* panel) {
	_panel = panel;
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
	QGraphicsScene::mousePressEvent(event);
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
	QGraphicsScene::mouseReleaseEvent(event);
}

void Scene::createLineEditWidget(const QString& name, QWidget* parent) {
	QHBoxLayout *hbox = new QHBoxLayout(parent);
	parent->setLayout(hbox);
	hbox->addWidget(new QLabel(name, parent));
	hbox->addWidget(new QLineEdit(parent));

}

void Scene::createSliderWidget(const QString& name, const Range* range, QWidget* parent) {
	QHBoxLayout *hbox = new QHBoxLayout(parent);
	parent->setLayout(hbox);
	hbox->addWidget(new QLabel(name, parent));
	hbox->addWidget(new QLineEdit(parent));
	QSlider* slider = new QSlider(Qt::Horizontal, parent);
	if (range)
		slider->setRange(range->first.toInt(), range->second.toInt());
	hbox->addWidget(slider);
}
