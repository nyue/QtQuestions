#pragma once

#include <QMainWindow>
#include <QCheckBox>
#include <QLabel>
#include <QTranslator>

class MainWindow : public QMainWindow
{
	// NOTICE THIS MACRO
    Q_OBJECT
    //
public:
    MainWindow(QWidget *parent = 0);
protected:
	// this event is called, when a new translator is loaded or the system language is changed
	// void changeEvent(QEvent*);
private:
	QCheckBox* ui_checkBox;
	QLabel* ui_label;
private slots:
	void doCheckBox();
};
