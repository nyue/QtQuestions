from PySide2 import QtWidgets, QtCore, QtGui

class BaseNode(QtWidgets.QGraphicsItem):

    def __init__(self, graphWidget):
        QtWidgets.QGraphicsItem.__init__(self)
        self.graphWidget = graphWidget
        self.setFlags(QtWidgets.QGraphicsItem.ItemIsSelectable |
                      QtWidgets.QGraphicsItem.ItemIsMovable)

    def mousePressEvent(self, event):  # Override base class
        print('BaseNode mousePressEvent')
        self.showWidget()

    def showWidget(self):
        print('BaseNode showWidget')


class FileNode(BaseNode):

    def __init__(self, graphWidget):
        BaseNode.__init__(self, graphWidget)

    # Minimal method to override
    def boundingRect(self):
        adjust = 2.0
        return QtCore.QRectF(-10.0 - adjust, -10.0 - adjust,
                             23.0 + adjust, 23.0 + adjust)

    # Minimal method to override
    def paint(self, painter, option, widget):
        painter.setPen(QtCore.Qt.NoPen)
        painter.setBrush(QtCore.Qt.darkGray)
        painter.drawRect(-10, -10, 20, 20)

    def showWidget(self):
        print('FileNode showWidget')
        vlayout = self.graphWidget.parent().findChild(QtWidgets.QVBoxLayout, "verticalLayout")
        if vlayout:
            vlayout.addWidget(QtWidgets.QTextEdit("Parameters"))
        if False:
            app = QtWidgets.QApplication.instance()
            #print(type(app))
            
            #print(app.findChild(QtWidgets.QVBoxLayout, "verticalLayout"))
            print(self.graphWidget.parent().findChild(QtWidgets.QVBoxLayout, "verticalLayout"))
            # print(type(self.graphWidget.parent()))
            if False:
                print(type(self.graphWidget))
                print(type(self.graphWidget.parent()))
                parent = self.graphWidget.parent()
                print(dir(parent))

class ComputeNode(BaseNode):

    def __init__(self, graphWidget):
        BaseNode.__init__(self, graphWidget)

    # Minimal method to override
    def boundingRect(self):
        adjust = 2.0
        return QtCore.QRectF(-10.0 - adjust, -10.0 - adjust,
                             23.0 + adjust, 23.0 + adjust)

    # Minimal method to override
    def paint(self, painter, option, widget):
        painter.setPen(QtCore.Qt.NoPen)
        painter.setBrush(QtCore.Qt.darkGray)
        painter.drawEllipse(-7, -7, 20, 20)

    def showWidget(self):
        print('ComputeNode showWidget')
        vlayout = self.graphWidget.parent().findChild(QtWidgets.QVBoxLayout, "verticalLayout")
        if vlayout:
            self.slider = QtWidgets.QSlider(QtCore.Qt.Horizontal)
            self.slider.setTickPosition(QtWidgets.QSlider.TicksAbove)
            self.slider.setMinimum(-17.0)
            self.slider.setMaximum(42.0)
            vlayout.addWidget(self.slider)

class GraphView(QtWidgets.QGraphicsView):
    def __init__(self, parent=None):
        QtWidgets.QGraphicsView.__init__(self, parent)
        scene = QtWidgets.QGraphicsScene(self)
        scene.setSceneRect(-200, -200, 400, 400)
        self.setScene(scene)
        self.setScene(scene)
        node1 = ComputeNode(self)
        node2 = FileNode(self)
        scene.addItem(node1)
        scene.addItem(node2)
        node1.setPos(120, 120)
        node1.setPos(80, 80)
