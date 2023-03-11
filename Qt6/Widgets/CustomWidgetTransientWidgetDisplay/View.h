#pragma once

#include "Scene.h"

#include <QGraphicsView>
#include <QMouseEvent>

class View : public QGraphicsView {
	Q_OBJECT
public:
	View(QWidget* parent = nullptr);
	Scene& myscene();
protected:
	virtual void keyReleaseEvent(QKeyEvent* event) override;
	/*
	virtual void mousePressEvent(QMouseEvent *event) override;
	virtual void mouseMoveEvent(QMouseEvent *event) override;
	virtual void mouseReleaseEvent(QMouseEvent *event) override;
	*/
	// virtual void contextMenuEvent(QContextMenuEvent *event) override;
private:
	Scene _scene;
};
