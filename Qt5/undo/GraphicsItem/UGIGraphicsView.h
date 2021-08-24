#pragma once

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QMouseEvent>
#include <vector>

class UGIGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit UGIGraphicsView(QWidget *parent = 0);
public slots:
    void mousePressEvent  (QMouseEvent *event) override;
    void mouseMoveEvent   (QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    // SEGraphicsScene scene;
    std::vector<QPointF> points;
    bool havePreviousPoint;
    QPointF previousPoint;
private:
    QPolygonF polygonalHull;
    QGraphicsPolygonItem polygonalHullItem;
};
