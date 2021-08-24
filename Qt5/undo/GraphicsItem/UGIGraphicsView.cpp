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
    this->scene()->setSceneRect(rect());
}

void UGIGraphicsView::mousePressEvent(QMouseEvent *event)
{
    double rad = 1;
    previousPoint = mapToScene(event->pos());
    /*
    scene->addEllipse(pt.x()-rad, pt.y()-rad, rad*2.0, rad*2.0,
                      QPen(), QBrush(Qt::SolidPattern));
*/
    qDebug() << "Press pos = " << previousPoint;
    havePreviousPoint = true;
    qreal radius = 20;
    this->scene()->addEllipse(event->pos().x(),event->pos().y(),radius,radius);
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
    QPointF pt = mapToScene(event->pos());
    QGraphicsView::mouseReleaseEvent(event);
}
