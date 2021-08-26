#include "UGIAddEllipseCommand.h"
#include <QDebug>

const int UndoCommandType = 100;
const int RedoCommandType = 101;

UGIAddEllipseCommand::UGIAddEllipseCommand(QGraphicsScene *scene,
                                           QGraphicsEllipseItem* ellipse,
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
    qDebug() << commandType;
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
    if(commandType == UndoCommandType)
    {
        scene->removeItem(_ellipse);
    } else if (commandType == RedoCommandType) {
        scene->addItem(_ellipse);
    }
    scene->update();
}
