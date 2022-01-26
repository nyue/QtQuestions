#pragma once

#include <QGraphicsView>

class WorldGraphicsView: public QGraphicsView {
    Q_OBJECT
public:
    explicit WorldGraphicsView(QWidget *parent = 0);
    ~WorldGraphicsView();
};
