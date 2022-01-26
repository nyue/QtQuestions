#pragma once

#include <QGraphicsView>

class CountryGraphicsView: public QGraphicsView {
    Q_OBJECT
public:
    explicit CountryGraphicsView(QWidget *parent = 0);
    ~CountryGraphicsView();
};
