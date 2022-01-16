#pragma once

#include "MyGraphicsScene.h"
#include <QGraphicsView>


class MyGraphicsView : public QGraphicsView {
public:
    explicit MyGraphicsView(QWidget *parent = 0);
    ~MyGraphicsView();
    void populate();
private:
    MyGraphicsScene _scene;
};
