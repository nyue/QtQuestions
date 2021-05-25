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

class MLIMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MLIMainWindow(QWidget *parent = 0);
    virtual ~MLIMainWindow();
private:
    Ui::MainWindow *ui;
private slots:
  void OnFileOpen();
  void OnFileClose();
};
