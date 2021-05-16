#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QComboBox>
#include <QActionGroup>
#include <QTranslator>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class GVMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    GVMainWindow(QWidget *parent = 0);
    virtual ~GVMainWindow();
private:
    Ui::MainWindow *ui;
private slots:
  void OnFileOpen();
  void OnFileClose();
  void OnFileSave();
};
