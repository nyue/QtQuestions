#include "UGIAddPointCommand.h"

const int UndoCommandType = 100;
const int RedoCommandType = 101;

UGIAddPointCommand::UGIAddPointCommand(QGraphicsScene *scene,
                          QPointF nPoint, QUndoCommand *parent):
    QUndoCommand(parent)
{
    this->scene = scene;
    /*
    foreach(QGraphicsItem* item, scene->selectedItems()){
        if(QAbstractGraphicsShapeItem* aItem =
                dynamic_cast<QAbstractGraphicsShapeItem*> (item)){
            oldColorMap.insert(aItem, aItem->brush().color());
        }
    }
    */
    this->nPoint = nPoint;
}

void UGIAddPointCommand::redo(){
    resetPoint(RedoCommandType);
}

void UGIAddPointCommand::undo(){
    resetPoint(UndoCommandType);
}

void UGIAddPointCommand::resetPoint(const int commandType){
    /*
    QMapIterator<QAbstractGraphicsShapeItem*, QColor> i(oldColorMap);
    while (i.hasNext()) {
         i.next();
         QBrush aBrush = i.key()->brush();
         if(commandType == UndoCommandType)
             aBrush.setColor(i.value());
         else
             aBrush.setColor(nColor);
         i.key()->setBrush(aBrush);
    }
    */
    scene->update();
}
