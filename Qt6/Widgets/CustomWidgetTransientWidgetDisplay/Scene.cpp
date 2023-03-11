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
}

void Scene::updateScene() {
}

void Scene::addNode() {
}

/* later
void Scene::setPanel(QVBoxLayout* panel) {
	_panel = panel;
}
*/

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
	QGraphicsScene::mousePressEvent(event);
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
	QGraphicsScene::mouseReleaseEvent(event);
}
