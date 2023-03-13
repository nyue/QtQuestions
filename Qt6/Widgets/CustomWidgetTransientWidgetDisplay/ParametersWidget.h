#pragma once

#include <QWidget>
#include <QVariant>
#include <QString>

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
private:
	typedef std::pair<QVariant,QVariant> Range;
	void addSliderWidget(const QString& name, QWidget* parent, const Range* range=nullptr);
	void addLineEditWidget(const QString& name, QWidget* parent);
};
