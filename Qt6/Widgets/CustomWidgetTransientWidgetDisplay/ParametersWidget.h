#pragma once

#include <QWidget>

#include <nlohmann/json.hpp>

/*!
 * \remark The plan is for one ParametersWidget to be associated with each
 *         Node::_parameterUI so that ownership is retained via the
 *         Node::_uiParent
 */
class ParametersWidget : public QWidget {
	Q_OBJECT
public:
	ParametersWidget(const std::string& label,
					 const nlohmann::json& attributes,
					 QWidget *parent = nullptr);
	virtual ~ParametersWidget();
};
