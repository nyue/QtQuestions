#include "UGIAddEllipseCommand.h"

const int UndoCommandType = 100;
const int RedoCommandType = 101;

UGIAddEllipseCommand::UGIAddEllipseCommand(QGraphicsScene *scene,
                                           const QGraphicsEllipseItem* ellipse,
                                           QUndoCommand *parent):
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
    this->_ellipse = ellipse;
}

void UGIAddEllipseCommand::redo(){
    resetEllipse(RedoCommandType);
}

void UGIAddEllipseCommand::undo(){
    resetEllipse(UndoCommandType);
}

void UGIAddEllipseCommand::resetEllipse(const int commandType){
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
