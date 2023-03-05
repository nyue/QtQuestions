#include "View.h"

#include <QPainter>
#include <QCoreApplication>
#include <QGraphicsScene>
#include <QDebug>

#include <iostream>

View::View(QWidget* parent) :
	QGraphicsView(parent)
{
	const float sceneWidth = 782.0;
	const float sceneHeight = 538.0;
	_scene.setSceneRect(0, 0, sceneWidth, sceneHeight);
	setScene(&_scene);
	setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
}

Scene& View::myscene()
{
	return _scene;
}

void View::keyReleaseEvent(QKeyEvent* event) {
	if (event->key() == Qt::Key_A)
		_scene.addNode();
	else if (event->key() == Qt::Key_Q)
		qApp->quit();
	else
		QGraphicsView::keyReleaseEvent(event);
}
