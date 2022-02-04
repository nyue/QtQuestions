#pragma once

#include "ui_MainWindow.h"
//
#include <QMainWindow>
#include <string>

namespace Ui {
class MainWindow;
}

class MyMainWindow : public QMainWindow {
public:
	explicit MyMainWindow(QWidget *parent = 0);
    virtual ~MyMainWindow();
private:
    Ui::MainWindow *ui;
};
