#pragma once

#include <QWidget>
#include <QPushButton>
#include <QComboBox>
#include <QActionGroup>
#include <QTranslator>
#include <QLabel>

namespace Ui {
class Form;
}

class CBForm : public QWidget
{
    Q_OBJECT
public:
    CBForm(QWidget *parent = 0);
    virtual ~CBForm();
private:
    Ui::Form *ui;
private slots:
    void generateText();
};
