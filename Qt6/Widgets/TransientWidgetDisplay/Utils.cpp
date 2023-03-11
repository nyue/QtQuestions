#include "Utils.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QSlider>

void attributeSliderWidget(const QString& name, const Range* range, QWidget* parent) {
	QHBoxLayout *hbox = new QHBoxLayout(parent);
	parent->setLayout(hbox);
	hbox->addWidget(new QLabel(name, parent));
	hbox->addWidget(new QLineEdit(parent));
	QSlider* slider = new QSlider(Qt::Horizontal, parent);
	if (range)
		slider->setRange(range->first.toInt(), range->second.toInt());
	hbox->addWidget(slider);
}

void attributeLineEditWidget(const QString& name, QWidget* parent) {
	QHBoxLayout *hbox = new QHBoxLayout(parent);
	parent->setLayout(hbox);
	hbox->addWidget(new QLabel(name, parent));
	hbox->addWidget(new QLineEdit(parent));
}
