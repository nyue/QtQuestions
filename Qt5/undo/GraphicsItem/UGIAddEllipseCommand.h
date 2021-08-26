#pragma once

#include <QUndoCommand>
#include <QGraphicsItem>
#include <QGraphicsScene>

class UGIAddEllipseCommand : public QUndoCommand
{
public:
    UGIAddEllipseCommand(QGraphicsScene *scene, QGraphicsEllipseItem* ellipse, QUndoCommand *parent = 0);
    void undo();
    void redo();
private:
    QGraphicsScene* scene;
    QGraphicsEllipseItem* _ellipse;
    void resetEllipse(const int commandType);
};
