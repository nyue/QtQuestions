#pragma once

#include "constants.h"

#include <QGraphicsItem>
#include <QFontMetrics>
#include <QPen>
#include <QRectF>
#include <QGraphicsSceneMouseEvent>
#include <QWidget>
#include <QVBoxLayout>

#include <nlohmann/json.hpp>

class Node : public QGraphicsItem
{
public:
    enum { Type = UserType + CustomGraphicsItemType::NodeItemType };
	Node(const std::string& name,
		 const nlohmann::json& attributes,
		 QVBoxLayout* panel,
		 QGraphicsItem *parent = nullptr);
	virtual ~Node();
	virtual QRectF boundingRect() const;
	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int type() const;
protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent* event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
private:
    std::string _name;
    float _width;
    float _height;
    float _radius;
    QPen _pen;
	QWidget _ui;
	QVBoxLayout* _panel; // where to update/replace the UI when node is selected
};

typedef std::map<std::string, Node*> NodeContainer;
