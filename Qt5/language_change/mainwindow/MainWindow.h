#pragma once

#include <QMainWindow>
#include <QCheckBox>
#include <QLabel>
#include <QComboBox>
#include <QTranslator>
#include <QCoreApplication>
#include <QSharedPointer>
#include <QVector>

class MainWindow : public QMainWindow
{
	// NOTICE THIS MACRO
    Q_OBJECT
    //
    typedef QSharedPointer<QTranslator> TranslatorShdPtr;
    struct abc {
        QString name;
        QString bcp47;
        TranslatorShdPtr translator;
    };
    typedef QVector<abc> LanguageTranslatorVecContainer;
public:
    MainWindow(QWidget *parent = 0);
private:
	QCheckBox* ui_checkBox;
	QLabel* ui_label;
    QComboBox* ui_languageComboBox;
    QTranslator ui_translator;
    QLabel* ui_iconLabel;
    LanguageTranslatorVecContainer _ltc;
private:
    void retranslateUi();
private slots:
    void handleLanguageChange(int index);
};
