#pragma once

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class UGIGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    UGIGraphicsScene(QObject *parent = nullptr);
    /*
    void load(const std::string& dgf_filename);
    void save(const std::string& dgf_filename);
    */
    void updateScene();
protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent* event);
    // DO NOT IMPLEMENT
    // virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
};
