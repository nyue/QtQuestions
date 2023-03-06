#pragma once

#include <QWidget>
#include <QString>
#include <QVariant>

typedef std::pair<QVariant,QVariant> Range;
QWidget* attributeSliderWidget(const QString& name, const Range* range=nullptr, QWidget* parent=nullptr);
QWidget* attributeLineEditWidget(const QString& name, QWidget* parent=nullptr);
