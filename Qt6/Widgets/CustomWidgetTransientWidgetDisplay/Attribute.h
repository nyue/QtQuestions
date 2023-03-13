#pragma once

#include <QGraphicsItem>
#include <QRectF>
#include <QPen>
#include <QPainter>

#include <map>
#include <string>
#include <memory>

class Attribute: public QGraphicsItem {
public:
	Attribute(const std::string &name,
			  bool labelOnRight,
			  float x, float y,
			  const std::string &type,
			  // later const QFontMetrics *fontMetrics,
			  QGraphicsItem *parent = nullptr);
    virtual ~Attribute();
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter,
    				   const QStyleOptionGraphicsItem *option,
					   QWidget *widget = nullptr);
    QWidget *widget();
    void updateValue(int value);
protected:
    QPainterPath getPainterPath() const;
private:
    QPen _pen;
    float _width;
    float _height;
    float _radius;
    bool _labelOnRight;
    QRectF _labelRect;
    std::string _label;
    std::string _type;
    // const QFontMetrics *_fontMetrics;
    QWidget *_widget;
};
