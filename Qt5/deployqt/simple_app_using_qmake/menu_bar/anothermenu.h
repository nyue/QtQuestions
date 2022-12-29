#pragma once

#include <QMainWindow>
#include <QApplication>

class AnotherMenu : public QMainWindow
{
    // NOTICE THIS MACRO
    Q_OBJECT
    //
  public:
    AnotherMenu(QWidget *parent = 0);
};
