#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QComboBox>
#include <QActionGroup>
#include <QTranslator>
#include <QLabel>
#include <QImage>
#include <QScrollArea>

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
    QImage image;
    QLabel *imageLabel;
    QScrollArea *scrollArea;
private slots:
  void OnFileOpen();
  void OnFileClose();
};
