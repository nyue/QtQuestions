#include "Scene.h"
#include "Node.h"

#include <cassert>
#include <iostream>

#include <QFont>
#include <QFontMetrics>

#include <boost/format.hpp>

Scene::Scene(QObject *parent)
// later :_panel(0)
{
	// later _fontMetrics = new QFontMetrics(property("font").value<QFont>());
}

Scene::~Scene() {
	// later delete _fontMetrics;
	NodeParametersMap::iterator iter = _nodeParameters.begin();
	for (;iter != _nodeParameters.end(); ++iter) {
		delete iter->second;
	}
}

void Scene::updateScene() {
}

void Scene::addNode() {
	nlohmann::json attributes;
	dummyAttributeSetup(attributes);	
	std::string node_name = (boost::format("Node_%04d") % items().count()).str();
    Node *node_ptr = new Node(node_name, attributes);
    /*
    ParametersWidget *pw_ptr = new ParametersWidget(node_name);
    _nodeParameters.insert(NodeParametersMap::value_type(node_ptr,pw_ptr));
    */
    addItem(node_ptr);
}

void Scene::replaceParamaters(Node* node_ptr) {
	// Don't do replace ... it leaks
	// Try re-parenting to a fix widget that is always present in the panel's vboxlayout

	std::cout << "Scene::replaceParamaters" << std::endl;
	std::cout << boost::format("Scene::replaceParamaters node name = '%1%' ") % node_ptr->name() << std::endl;
	printf("node_ptr->ui() = %p _panel->count() = %d\n",node_ptr->getUI(),_panel->count());
	// ParametersWidget *pw_ptr = _nodeParameters.at(node_ptr);
	if (_panel->count()==0) {
		_panel->addWidget(node_ptr->getUI());
	} else {
		QLayoutItem *item = _panel->itemAt(0);
		if (item) {
			std::cout << "Scene::replaceParamaters one item found" << std::endl;
			// Check if same parameter UI
			if (item->widget() != node_ptr->getUI()) {
				_panel->removeItem(item);
				node_ptr->returnUI(item->widget());
				delete item;
				_panel->addWidget(node_ptr->getUI());
			} else {
				std::cout << "Scene::replaceParamaters SAME PARAMETER WIDGET" << std::endl;
			}
		}
	}
	return;
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

void Scene::dummyAttributeSetup(nlohmann::json& attributes) {
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
	
	const size_t num_extra_string_attributes = 2;
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
	
}
