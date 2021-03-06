#pragma once

#include "AbstractGraphicsItem.h"

#include <QGraphicsScene>
#include <QSharedPointer>
#include <map>

class MyGraphicsScene : public QGraphicsScene {

	typedef QSharedPointer<AbstractGraphicsItem> QGISharedPointer;
	typedef std::map<std::string,QGISharedPointer> QGIMap;
public:
    explicit MyGraphicsScene(QObject *parent = 0);
    ~MyGraphicsScene();
    void setup();
    void populate();
private:
    QGIMap _items;
};
