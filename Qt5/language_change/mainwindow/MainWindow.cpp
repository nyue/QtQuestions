#include "MainWindow.h"
#include <QVBoxLayout>
#include <QDebug>
#include <QUiLoader>
#include <QFile>
#include <QDir>
#include <QDirIterator>
#include <QWidget>
#include <QApplication>

QString extract_bcp47(const QString language_file_path) {
    QStringList dotSplit = language_file_path.split(".");
    QString nameWithBCP47 = dotSplit[dotSplit.size()-2];
    QStringList underscoreSplit = nameWithBCP47.split("_");
    QString bcp47 = underscoreSplit[underscoreSplit.size()-1];
    return bcp47;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QUiLoader loader;
    QFile file(":/designer/mainwindow.ui");
    file.open(QFile::ReadOnly);
    QWidget *widget = loader.load(&file, parent);
    loader.setTranslationEnabled(true);
    file.close();
    setCentralWidget(widget);

    ui_checkBox = findChild<QCheckBox*>("checkBox");
    QObject::connect(ui_checkBox, SIGNAL(clicked()),  this, SLOT(doCheckBox()));

    // Build language drop down menu
    {
        ui_languageComboBox = findChild<QComboBox*>("comboBox");
        Q_ASSERT(ui_languageComboBox);
        connect(ui_languageComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(handleLanguageChange(int)));

        ui_languageGroup = new QActionGroup(ui_languageComboBox);
        Q_ASSERT(ui_languageGroup);
        ui_languageGroup->setExclusive(true);
        connect(ui_languageGroup, SIGNAL (triggered(QAction *)), this, SLOT (slotLanguageChanged(QAction *)));

        // Find available languages

        // https://stackoverflow.com/questions/28463090/how-to-iterate-through-only-certain-type-of-files-using-qdiriterator#28463194
        QDirIterator it(QString(":/language/.qm"), QStringList() << "*.qm", QDir::Files, QDirIterator::Subdirectories);
        while (it.hasNext()) {
            QString item = it.next();
            QString language = extract_bcp47(item);
            QLocale locale(language);
            /*
            qDebug() << item;
            qDebug() << language;
            qDebug() << QLocale::countryToString(locale.country());
            qDebug() << QLocale::languageToString(locale.language());
            */

            // Create a translator for each language found
            TranslatorShdPtr t(new QTranslator);
            if (t->load(item))
            {
                struct abc stuff{QLocale::languageToString(locale.language()),t};
                _ltc.push_back(stuff);
            }

        }

        // Iterate the languages found to build the drop down list
        // QMapIterator<QString, TranslatorShdPtr> i(_ltc);
        QVectorIterator<struct abc> ii(_ltc);
        while (ii.hasNext()) {
            struct abc s = ii.next();
            qDebug() << s.name << ": " << s.translator;
        }

    }

    ui_iconLabel = findChild<QLabel*>("iconLabel");
    Q_ASSERT(ui_iconLabel);
    QIcon languageIcon;
    languageIcon.addFile(":/icons/Font_Awesome_5_solid_language.svg");
    // languageIcon.addFile(":/icons/wl.png");
    QPixmap iconPixmap = languageIcon.pixmap(32);
    ui_iconLabel->setPixmap(iconPixmap);
    ui_iconLabel->resize(iconPixmap.width(),iconPixmap.height());

}


void MainWindow::doCheckBox() {
    qDebug() << "doCheckBox() called = " << ui_checkBox->isChecked();
    if (ui_checkBox->isChecked())
    {
        QString langFile = QString(":/language/.qm/mlc_de.qm");
        if (ui_translator.load(langFile)) {
            qDebug() << "DE Sucessful";
            qApp->removeTranslator(&ui_translator);
            bool installed = qApp->installTranslator(&ui_translator);
            if (installed) {
                qDebug() << "DE installed";
                this->retranslateUi();
            }
        }
        else
        {
            qDebug() << "DE Unsuccessful";
        }
    }
    else
    {
        QString langFile = QString(":/language/.qm/mlc_C.qm");

        if (ui_translator.load(langFile)) {
            qDebug() << "C Successful";
            qApp->removeTranslator(&ui_translator);
            bool installed = qApp->installTranslator(&ui_translator);
            if (installed) {
                qDebug() << "C installed";
                this->retranslateUi();
            }
        }
        else
        {
            qDebug() << "C Unsuccessful";
        }
    }
}

void MainWindow::slotLanguageChanged(QAction* action)
{
    qDebug() << "slotLanguageChanged";
}

void MainWindow::handleLanguageChange(int index)
{
    qDebug() << "handleLanguageChange = " << index;
    qDebug() << "handleLanguageChange = " << _ltc[index].name;
}
