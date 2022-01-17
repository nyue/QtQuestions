#include "MyGraphicsScene.h"
#include "CircleGraphicsItem.h"
#include "SquareGraphicsItem.h"
#include <QGraphicsRectItem>

MyGraphicsScene::MyGraphicsScene(QObject *parent)
:QGraphicsScene(parent)
{
	setup();
}

MyGraphicsScene::~MyGraphicsScene()
{
}

void MyGraphicsScene::setup()
{
	std::pair<QGIMap::iterator,bool> ret;
	if (true)
	{
		QGISharedPointer sharedItem(new SquareGraphicsItem());
		ret = this->_items.insert(QGIMap::value_type("mysquare",sharedItem));
	}
	if (true)
	{
		QGISharedPointer sharedItem(new CircleGraphicsItem());
		ret = this->_items.insert(QGIMap::value_type("mycircle",sharedItem));
	}
}

void MyGraphicsScene::populate()
{
	printf("MyGraphicsScene::populate()\n");

	for (QGIMap::iterator iter=_items.begin();iter!=_items.end();++iter)
	{
		printf("MyGraphicsScene::populate() item\n");
		addItem(iter->second.data());
	}
}
