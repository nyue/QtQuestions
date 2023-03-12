#pragma once

#include <QWidget>

#include <nlohmann/json.hpp>

class ParametersWidget : public QWidget {
	Q_OBJECT
public:
	ParametersWidget(const std::string& label,
					 const nlohmann::json& attributes,
					 QWidget *parent = nullptr);
	virtual ~ParametersWidget();
};
