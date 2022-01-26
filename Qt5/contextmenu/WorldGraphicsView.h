#pragma once

#include <QGraphicsView>
#include <QMenu>

class WorldGraphicsView: public QGraphicsView {
    Q_OBJECT
public:
    explicit WorldGraphicsView(QWidget *parent = 0);
    ~WorldGraphicsView();
    virtual void contextMenuEvent(QContextMenuEvent *event) override;
private:
    QMenu* _contextMenu;
public:
	void contextMenuHandler(const QString param1,const QString param2);
};
