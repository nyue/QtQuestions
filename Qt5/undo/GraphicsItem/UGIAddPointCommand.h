#pragma once

#include <QUndoCommand>
#include <QGraphicsItem>
#include <QGraphicsScene>

class UGIAddPointCommand : public QUndoCommand
{
public:
    UGIAddPointCommand(QGraphicsScene *scene, QPointF nPoint, QUndoCommand *parent = 0);
    void undo();
    void redo();
private:
    QGraphicsScene* scene;
    QPointF nPoint;
    void resetPoint(const int commandType);
};
