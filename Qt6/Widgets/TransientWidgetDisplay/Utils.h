#pragma once

#include <QWidget>
#include <QString>
#include <QVariant>

typedef std::pair<QVariant,QVariant> Range;
void attributeSliderWidget(const QString& name, const Range* range, QWidget* parent);
void attributeLineEditWidget(const QString& name, QWidget* parent);
