#include "Form.h"
#include <QVBoxLayout>
#include <QUiLoader>
#include <QFile>
#include <QApplication>
#include <QDirIterator>
#include <QDebug>
#include <QFile>

#include <iostream>

Form::Form(QWidget *parent)
	: QWidget(parent)
{

	QUiLoader loader;
	QFile file(":/designer/form.ui");
	file.open(QFile::ReadOnly);
	QWidget *myWidget = loader.load(&file, this);
    loader.setLanguageChangeEnabled(true);
    file.close();

	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(myWidget);
	setLayout(layout);
}

void Form::doCheckBox() {
	std::cout << "doValidate() called" << std::endl;
}
