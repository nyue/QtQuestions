#pragma once

#include "Node.h"
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class Scene: public QGraphicsScene {
Q_OBJECT
public:
	Scene(QObject *parent = nullptr);
	virtual ~Scene();
	void updateScene();
#ifdef OLD_APPROACH
	Node* addNodeOld();
#else // OLD_APPROACH
	void addNode();
#endif // OLD_APPROACH
	void setPanel(QVBoxLayout* panel);
protected:
	virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
	// DO NOT IMPLEMENT
	// virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
	virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private:
#ifdef OLD_APPROACH
	NodeContainer _nodes;
#else // OLD_APPROACH
	// https://stackoverflow.com/questions/612328/difference-between-struct-and-typedef-struct-in-c
	typedef struct {
		NodeShdPtr _node; // this is always added via addItem to a Scene so memory management is done via Scene
		QWidget* _ui; // Not sure, hence this test about memory mangement
	} NodeUI;
	typedef std::map<std::string,NodeUI> NodeUIContainer;
	NodeUIContainer _nodesAndUIs;
#endif // OLD_APPROACH
	QVBoxLayout *_panel; // to facilitate panel ui update/replace when adding Node
    QFontMetrics *_fontMetrics;
private:
	typedef std::pair<QVariant,QVariant> Range;
    void createLineEditWidget(const QString& name, QWidget* parent);
    void createSliderWidget(const QString& name, const Range* range, QWidget* parent);
};

