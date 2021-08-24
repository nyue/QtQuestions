#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QComboBox>
#include <QActionGroup>
#include <QTranslator>
#include <QLabel>
#include <QUndoStack>
#include "UGIGraphicsScene.h"

namespace Ui {
class MainWindow;
}

class UGIMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    UGIMainWindow(QWidget *parent = 0);
    virtual ~UGIMainWindow();

private:
    Ui::MainWindow *ui;
    UGIGraphicsScene *scene;
    QUndoStack *undoStack;
    void addUndoPoint() {};
private slots:
  void OnFileClose();
};
