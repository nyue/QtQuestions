#pragma once

#include <QWidget>
#include <QVariant>
#include <QString>
#include <QVBoxLayout>

#include <nlohmann/json.hpp>

// Forward declaration
class Node;

/*!
 * \remark The plan is for one ParametersWidget to be associated with each
 *         Node::_parameterUI so that ownership is retained via the
 *         Node::_uiParent
 */
class ParametersWidget : public QWidget {
//	Q_OBJECT
public:
	ParametersWidget(const std::string& label,
					 const nlohmann::json& attributes,
					 Node* node,
					 QWidget *parent);
	virtual ~ParametersWidget();
private:
	typedef std::pair<QVariant,QVariant> Range;
	void addSliderWidget(const QString& name, QVBoxLayout* layout, const Range* range=nullptr);
	void addLineEditWidget(const QString& name, QVBoxLayout* layout);
	void onSliderValueChange(const QString& name, int value);
	Node* _node;
	/*
private slots:
	void onSliderValueChange();
	void onTextEditValueChange();
	*/
};
