#pragma once

#include "Node.h"
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class Scene: public QGraphicsScene {
Q_OBJECT
public:
	Scene(QObject *parent = nullptr);
	void updateScene();
	void addNode();
protected:
	virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
	// DO NOT IMPLEMENT
	// virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
	virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private:
	NodeContainer _nodes;
};

