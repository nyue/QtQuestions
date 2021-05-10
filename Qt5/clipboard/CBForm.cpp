#include "CBForm.h"
#include "ui_form.h"
#include <QClipboard>

CBForm::CBForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form)
{
    ui->setupUi(this);

    connect( ui->quitPushButton, SIGNAL(clicked()), this, SLOT(close() ) );
    connect( ui->generatePushButton, SIGNAL(clicked()), this, SLOT(generateText() ) );

}

CBForm::~CBForm()
{
    delete ui;
}

void CBForm::generateText()
{
    QClipboard* qclip = QApplication::clipboard();

    QString some_text("Hello, this is a test of the clipboard");

    qclip->setText(some_text);
    ui->plainTextEdit->setPlainText(some_text);

}
