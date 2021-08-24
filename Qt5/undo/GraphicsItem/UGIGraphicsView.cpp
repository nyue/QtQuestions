#include "UGIGraphicsView.h"
#include <QPointF>
#include <QDebug>

UGIGraphicsView::UGIGraphicsView(QWidget *parent)
    : QGraphicsView(parent)
    , havePreviousPoint(false)
{
    setMouseTracking(true); // Required to track mouse when NOT clicked
}

void UGIGraphicsView::resizeEvent(QResizeEvent *event)
{
    qDebug() << "UGIGraphicsView::resizeEvent";
    this->scene()->setSceneRect(rect());
}

void UGIGraphicsView::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "UGIGraphicsView::mousePressEvent";
    const qreal radius = 5;
    const qreal half_radius = radius * 0.5;
    this->scene()->addEllipse(event->pos().x()-half_radius,event->pos().y()-half_radius,radius,radius);

    QGraphicsView::mousePressEvent(event);
}

void UGIGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() == Qt::NoButton) {
        // Free movement
    } if (event->buttons() == Qt::LeftButton) {
        // Left mouse button down
    }
}

void UGIGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "UGIGraphicsView::mouseReleaseEvent";
    QGraphicsView::mouseReleaseEvent(event);
}
