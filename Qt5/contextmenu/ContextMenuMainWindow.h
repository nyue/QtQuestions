#pragma once

#include "ui_MainWindow.h"
//
#include <QMainWindow>
#include <string>

namespace Ui {
class MainWindow;
}

class ContextMenuMainWindow : public QMainWindow {
public:
	explicit ContextMenuMainWindow(QWidget *parent = 0);
    virtual ~ContextMenuMainWindow();
private:
    Ui::MainWindow *ui;
};
