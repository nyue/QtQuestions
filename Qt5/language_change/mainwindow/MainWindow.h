#pragma once

#include <QMainWindow>
#include <QCheckBox>
#include <QLabel>
#include <QComboBox>
#include <QTranslator>
#include <QCoreApplication>
#include <QSharedPointer>
#include <QActionGroup>
#include <QVector>

class MainWindow : public QMainWindow
{
	// NOTICE THIS MACRO
    Q_OBJECT
    //
    typedef QSharedPointer<QTranslator> TranslatorShdPtr;
    // typedef QMap<QString,TranslatorShdPtr> LanguageTranslatorMapContainer;
    struct abc {
        QString name;
        TranslatorShdPtr translator;
    };

    typedef QVector<abc> LanguageTranslatorVecContainer;
public:
    MainWindow(QWidget *parent = 0);
protected:
	// this event is called, when a new translator is loaded or the system language is changed
	// void changeEvent(QEvent*);
private:
	QCheckBox* ui_checkBox;
	QLabel* ui_label;
    QComboBox* ui_languageComboBox;
    QActionGroup* ui_languageGroup;

    QTranslator ui_translator;
    QLabel* ui_iconLabel;
    void retranslateUi()
    {
        // setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        ui_label = findChild<QLabel*>("label");
        if (ui_label)
            ui_label->setText(QCoreApplication::translate("MainWindow", "Hello", nullptr));
        // ui_checkBox->setText(QCoreApplication::translate("MainWindow", "CheckBox", nullptr));
        // ui_pushButonn->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
    } // retranslateUi
    LanguageTranslatorVecContainer _ltc;
private slots:
	void doCheckBox();
    void slotLanguageChanged(QAction* action);
    void handleLanguageChange(int index);
};
