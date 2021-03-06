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
private slots:
  void OnFileOpen();
  void OnFileClose();
  void OnFileSave();
  void OnPopulate();
};
