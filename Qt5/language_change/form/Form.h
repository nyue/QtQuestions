#pragma once

#include <QWidget>
#include <QPushButton>
#include <QComboBox>
#include <QActionGroup>
#include <QTranslator>

class Form : public QWidget
{
	// NOTICE THIS MACRO
    Q_OBJECT
    //
public:
    Form(QWidget *parent = 0);
protected:
	// this event is called, when a new translator is loaded or the system language is changed
	// void changeEvent(QEvent*);
private:
	QPushButton* ui_checkBox;
							
private slots:
	void doCheckBox();
};
