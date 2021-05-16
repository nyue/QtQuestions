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

class IOMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    IOMainWindow(QWidget *parent = 0);
    virtual ~IOMainWindow();
private:
    Ui::MainWindow *ui;
private slots:
  void OnFileOpen();
  void OnFileClose();
  // void OnFileSave();
};
