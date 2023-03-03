#pragma once

const float attributeWidth = 20.0;
const float attributeHeight = attributeWidth;
const float attributeRadius = 0.1 * attributeWidth;

const float nodeWidth = 200.0;
const float nodeHeight = nodeWidth;
const float nodeRadius = 0.1 * nodeWidth;

enum CustomGraphicsItemType {NodeItemType=1,AttributeItemType};

const int NodeItemZ = 1;
const int ConnectionItemZ = 2;
const int AttributeItemZ = 3;
