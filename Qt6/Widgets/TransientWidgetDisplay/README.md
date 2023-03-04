# Transient display of Widgets

## Context
I have some widgets associated with a given QGraphicsItem subclass call Node,
when a Node is created, I will also create a QWidget (lets call it Panel)
with QSlider and QText.

The slider and text input will control what is displayed inside a given Node.

My mainwindow costs of a horizonally laid out QGraphicsView and a blank
QWidget, my plan is to house the Panel inside this blank QWidget

When I select a given Node, I want to display the panel associated with that
particular Node instance

During the running of the Qt application, I'd want to jump between different
Node by selecting them

What is the idiomatic way to manage all the separate display of the Panel
when a given Node is selected. I believe I should not recreate the Panel from
scratch but to somehow track/associate them with a given Node, is that correct?

Additionally, I only want to display one given Panel at a time so how should
I swap out a Panel widget in my blank widget area ? What Qt keyword should
I look up to read more about it ?


## Resources
https://stackoverflow.com/questions/16795494/add-widgets-to-a-scrollarea
