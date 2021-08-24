#include "UGIGraphicsScene.h"
#include <QDebug>

UGIGraphicsScene::UGIGraphicsScene(QObject *parent)
    : QGraphicsScene(parent)
{
}

void UGIGraphicsScene::updateScene()
{
}

void UGIGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    qDebug() << "SEGraphicsScene::mousePressEvent";
    QGraphicsScene::mousePressEvent(event);
}

void UGIGraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
    qDebug() << "SEGraphicsScene::mouseReleaseEvent";
}
