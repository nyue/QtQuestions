#pragma once

#include <QGraphicsItem>

class AbstractGraphicsItem : public QGraphicsItem {
public:
	explicit AbstractGraphicsItem(QGraphicsItem *parent = nullptr);
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
    virtual QRectF boundingRect() const;
protected:
    QRectF _bound;
    std::string _shape;
};
