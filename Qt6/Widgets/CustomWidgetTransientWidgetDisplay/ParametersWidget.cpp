#include "ParametersWidget.h"
#include "Node.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QSlider>
#include <QLineEdit>

#include <iostream>
#include <boost/format.hpp>

ParametersWidget::ParametersWidget(const std::string& label,
								   const nlohmann::json& attributes,
								   Node* node,
								   QWidget *parent)
:QWidget(parent)
,_node(node)
{
	std::cout << boost::format("ParametersWidget::ParametersWidget label = '%1%'") % label << std::endl;
	/* 'this' keyword is important, we tell the widget the parent within to be
	 * shown
	 */
	QVBoxLayout *layout = new QVBoxLayout(this);
	layout->addWidget(new QLabel(label.c_str()));
	if (attributes.contains("in")) {
		nlohmann::json in_attributes = attributes["in"];
	    for (nlohmann::json::iterator in_attr = in_attributes.begin(); in_attr != in_attributes.end(); ++in_attr) {
	    	std::string label = in_attr.key();
	    	nlohmann::json value = in_attr.value();
	    	std::string type = value["type"];
	    	if (type.compare("string")==0) {
	    		addLineEditWidget(label.c_str(), layout);
	    	} else if (type.compare("int")==0) {
	    		addSliderWidget(label.c_str(), layout);
	    	}
	    }
	}
}

ParametersWidget::~ParametersWidget()
{

}

void ParametersWidget::addSliderWidget(const QString& name, QVBoxLayout* layout, const Range* range) {
	QWidget* result = new QWidget();
	QHBoxLayout *hbox = new QHBoxLayout();
	result->setLayout(hbox);
	hbox->addWidget(new QLabel(name));
	hbox->addWidget(new QLineEdit());
	QSlider* slider = new QSlider(Qt::Horizontal);
	if (range)
		slider->setRange(range->first.toInt(), range->second.toInt());
	hbox->addWidget(slider);
	layout->addWidget(result);
    connect(slider, &QSlider::valueChanged,
        [this, name](int value)
        {
    	onSliderValueChange(name, value);
        });
}

void ParametersWidget::addLineEditWidget(const QString& name, QVBoxLayout* layout) {
	QWidget* result = new QWidget();
	QHBoxLayout *hbox = new QHBoxLayout();
	result->setLayout(hbox);
	hbox->addWidget(new QLabel(name));
	hbox->addWidget(new QLineEdit());
	layout->addWidget(result);
}

void ParametersWidget::onSliderValueChange(const QString& name, int value) {
	// std::cout << boost::format("name = '%1%', value = %2%") % name.toStdString() % intValue << std::endl;
	_node->onSliderValueChange(name, value);
}

/*
void ParametersWidget::onSliderValueChange() {

}

void ParametersWidget::onTextEditValueChange() {

}

*/
