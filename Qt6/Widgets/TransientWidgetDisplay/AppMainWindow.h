#pragma once

#include "ui_MainWindow.h"
//
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class AppMainWindow : public QMainWindow {
public:
    explicit AppMainWindow(QWidget *parent = 0);
    virtual ~AppMainWindow();
private:
    Ui::MainWindow *ui;
    QWidget *_scrollAreaWidgetContents;
private slots:
	void OnAdd();
    void OnReplace();
};
