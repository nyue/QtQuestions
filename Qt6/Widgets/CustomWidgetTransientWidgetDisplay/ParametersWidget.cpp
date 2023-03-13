#include "ParametersWidget.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QSlider>
#include <QLineEdit>

#include <iostream>
#include <boost/format.hpp>

ParametersWidget::ParametersWidget(const std::string& label,
								   const nlohmann::json& attributes,
								   QWidget *parent)
:QWidget(parent)
{
	std::cout << boost::format("ParametersWidget::ParametersWidget label = '%1%'") % label << std::endl;
	QVBoxLayout *layout = new QVBoxLayout(this); // this keyword is important, we tell the widget the parent within be showed
	layout->addWidget(new QLabel(label.c_str()));

	if (attributes.contains("in")) {
		nlohmann::json in_attributes = attributes["in"];
	    for (nlohmann::json::iterator in_attr = in_attributes.begin(); in_attr != in_attributes.end(); ++in_attr) {
#ifdef IMPL
	    	if (_type.compare("string")==0) {
	    		_widget = attributeLineEditWidget(_label.c_str());
	    	} else if (_type.compare("int")==0) {
	    		Range range;
	    		range.first.setValue<int>(0);
	    		range.second.setValue<int>(10);
	    		_widget = attributeSliderWidget(_label.c_str(),&range);

	    		// Register action
	    		QSlider *slider = _widget->findChild<QSlider *>();
	    		slider->connect(slider, &QSlider::valueChanged,
	    	            [this](int intValue)
	    	            {
	    					updateValue(intValue);
	    	            });
	    	}
#endif
	    }
	}
}

ParametersWidget::~ParametersWidget()
{

}

void ParametersWidget::addSliderWidget(const QString& name, QWidget* parent, const Range* range) {
	QWidget* result = new QWidget(parent);
	QHBoxLayout *hbox = new QHBoxLayout();
	result->setLayout(hbox);
	hbox->addWidget(new QLabel(name));
	hbox->addWidget(new QLineEdit());
	QSlider* slider = new QSlider(Qt::Horizontal);
	if (range)
		slider->setRange(range->first.toInt(), range->second.toInt());
	hbox->addWidget(slider);
}

void ParametersWidget::addLineEditWidget(const QString& name, QWidget* parent) {
	QWidget* result = new QWidget(parent);
	QHBoxLayout *hbox = new QHBoxLayout();
	result->setLayout(hbox);
	hbox->addWidget(new QLabel(name));
	hbox->addWidget(new QLineEdit());
}
