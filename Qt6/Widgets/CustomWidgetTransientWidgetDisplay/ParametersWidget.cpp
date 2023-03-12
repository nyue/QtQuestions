#include "ParametersWidget.h"

#include <QVBoxLayout>
#include <QLabel>

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
}

ParametersWidget::~ParametersWidget()
{

}
