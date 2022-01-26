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
private slots:
	void contextMenuHandler(QString parameter1, QString parameter2);
};
