#pragma once

#include "Node.h"
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QVBoxLayout>

class Scene: public QGraphicsScene {
Q_OBJECT
public:
	Scene(QObject *parent = nullptr);
	virtual ~Scene();
	void updateScene();
	void addNode();
	// later void setPanel(QVBoxLayout* panel);
protected:
	virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
	// DO NOT IMPLEMENT
	// virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
	virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private:
	NodeContainer _nodes;
	// later QVBoxLayout *_panel; // to facilitate panel ui update/replace when adding Node
    // later QFontMetrics *_fontMetrics;
};

