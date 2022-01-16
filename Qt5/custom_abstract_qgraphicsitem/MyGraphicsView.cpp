#include "MyGraphicsView.h"

#include <QGraphicsRectItem>

MyGraphicsView::MyGraphicsView(QWidget *parent)
:QGraphicsView(parent)
{
	this->setScene(&_scene);
	MyGraphicsScene *scenePtr = dynamic_cast<MyGraphicsScene *>(this->scene());
	if (scenePtr)
	{
		printf("scenePtr %p\n",scenePtr);
		QRectF rect;
		rect.setWidth(200);
		rect.setHeight(100);
		QGraphicsRectItem rectItem(rect);

		// scenePtr->addRect(0, 0, 100,100);
		scenePtr->addItem(&rectItem);
	}
}

MyGraphicsView::~MyGraphicsView()
{

}

void MyGraphicsView::populate()
{
	_scene.populate();
}
