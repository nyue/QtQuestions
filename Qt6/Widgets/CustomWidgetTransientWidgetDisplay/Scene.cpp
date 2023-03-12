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
	std::string node_name = (boost::format("Node_%04d") % items().count()).str();
    Node *node_ptr = new Node(node_name);
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
	if (_panel->count()==1) {
		QWidget *pAchorWidget = _panel->itemAt(0)->widget();
		if (node_ptr->getUI()->parentWidget() != pAchorWidget) {
			std::cout << "Scene::replaceParamaters SOMETHING TO DO" << std::endl;
			// node_ptr->getUI()->setParent(_panel);
			_panel->addWidget(node_ptr->getUI());
		} else {
			std::cout << "Scene::replaceParamaters NOTHING TO DO" << std::endl;
		}
		/*
		QWidget *pExistingWidget = _panel->itemAt(0)->widget();
		if (pExistingWidget != node_ptr->getUI()) {
			// Only if not the same widget
			printf("INSIDE ZZZZZZZZZZZZZZZZ\n");
			_panel->replaceWidget(pExistingWidget, node_ptr->ui());
			pExistingWidget->setParent(nullptr); // Important, otherwise it still shows up
		}
		*/
	} else {
		std::cout << "Scene::replaceParamaters _panel non zero" << std::endl;

	}


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
