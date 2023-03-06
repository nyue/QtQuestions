#include "Utils.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QSlider>

QWidget* attributeSliderWidget(const QString& name, const Range* range, QWidget* parent) {

	QWidget* result = new QWidget(parent);
	QHBoxLayout *hbox = new QHBoxLayout();
	result->setLayout(hbox);
	hbox->addWidget(new QLabel(name));
	hbox->addWidget(new QLineEdit());
	QSlider* slider = new QSlider(Qt::Horizontal);
	if (range)
		slider->setRange(range->first.toInt(), range->second.toInt());
	hbox->addWidget(slider);
	return result;
}

QWidget* attributeLineEditWidget(const QString& name, QWidget* parent) {
	QWidget* result = new QWidget(parent);
	QHBoxLayout *hbox = new QHBoxLayout();
	result->setLayout(hbox);
	hbox->addWidget(new QLabel(name));
	hbox->addWidget(new QLineEdit());
	return result;
}
