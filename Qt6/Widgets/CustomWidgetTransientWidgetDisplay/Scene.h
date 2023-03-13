#pragma once

#include "Node.h"
#include "ParametersWidget.h"

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QVBoxLayout>

#include <nlohmann/json.hpp>

#include <map>

class Scene: public QGraphicsScene {
// Q_OBJECT unsure if this is necessary
public:
	Scene(QObject *parent = nullptr);
	virtual ~Scene();
	void updateScene();
	void addNode();
	void replaceParamaters(Node* node_ptr);
	void setPanel(QVBoxLayout* panel);
protected:
	virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
	// DO NOT IMPLEMENT
	// virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
	virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private:
	typedef std::map<const Node*,ParametersWidget*> NodeParametersMap;
	NodeParametersMap _nodeParameters;
	// NodeContainer _nodes;
	QVBoxLayout *_panel; // to facilitate panel ui update/replace when adding Node
    // later QFontMetrics *_fontMetrics;
	void dummyAttributeSetup(nlohmann::json& attributes); // dummy for now, eventually need to get them from the API Nov::Node SDK
};

