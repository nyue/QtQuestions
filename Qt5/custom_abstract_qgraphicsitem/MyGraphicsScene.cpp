#include "MyGraphicsScene.h"
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
	QRectF rect;
	rect.setWidth(200);
	rect.setHeight(100);
	// QGraphicsRectItem rectItem(rect);

	QGISharedPointer sharedItem(new QGraphicsRectItem());

	QSharedPointer<QGraphicsRectItem> derived = qSharedPointerDynamicCast<QGraphicsRectItem>( sharedItem );

	derived->setRect(rect);


	std::pair<QGIMap::iterator,bool> ret;
	ret = this->_items.insert(QGIMap::value_type("hello",sharedItem));
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
