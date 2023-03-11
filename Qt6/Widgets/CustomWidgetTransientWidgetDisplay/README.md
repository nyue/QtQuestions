# Custom widget for transient display of widgets

## Context

This is a variation of the other transient display via the use of a custom widget

We have found that creating/managing the resource life time for those widgets are challenging when done via a QGraphicsItem object
because they themselves are not QObject derived and we are constantly finding memory leaks reported in Valgrind.

The plan is as follows.

Copy the widget, graphicsitem and layout as the "TransientWidgetDisplay" example but introduce a new custom widget call
ParametersWidget.

We plan to manage the ParametersWidget life time by virtue of it have Q_OBJECT in the header and a QWidget derived class.

We have found that performing replaceWidget() is problematic in terms of memory and resource lifetime management.
Hence, this new code should ensure that replaceWidget() will not result in memory leaks before we add too much features
into the ParametersWidget class. It should be sufficient to simply display the name of an associated Node to verify
if there are memory leaks in Valgrind.

