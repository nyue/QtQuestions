#pragma once

#include <QUndoCommand>
#include <QGraphicsItem>
#include <QGraphicsScene>

class UGIAddEllipseCommand : public QUndoCommand
{
public:
    UGIAddEllipseCommand(QGraphicsScene *scene, const QGraphicsEllipseItem* ellipse, QUndoCommand *parent = 0);
    void undo();
    void redo();
private:
    QGraphicsScene* scene;
    const QGraphicsEllipseItem* _ellipse;
    void resetEllipse(const int commandType);
};
