#pragma once

#include "constants.h"

#include <QGraphicsItem>
#include <QFontMetrics>
#include <QPen>
#include <QRectF>
#include <QGraphicsSceneMouseEvent>

#include <nlohmann/json.hpp>

class Node : public QGraphicsItem
{
public:
    enum { Type = UserType + CustomGraphicsItemType::NodeItemType };
	Node(const std::string& name,
		 const nlohmann::json& attributes,
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
};

typedef std::map<std::string, Node*> NodeContainer;
