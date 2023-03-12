#pragma once

#include <QWidget>

class ParametersWidget : public QWidget {
	Q_OBJECT
public:
	ParametersWidget(const std::string& label, QWidget *parent = nullptr);
	virtual ~ParametersWidget();
};
