# The purpose of this example is not to illustrate details
# and feature of QGraphics* stuff but the minimal
# implementation required to display something

from PySide2 import QtWidgets, QtCore, QtGui
import sys


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


class GraphWidget(QtWidgets.QGraphicsView):
    def __init__(self, parent=None):
        QtWidgets.QGraphicsView.__init__(self, parent)
        scene = QtWidgets.QGraphicsScene(self)
        scene.setSceneRect(-200, -200, 400, 400)
        self.setScene(scene)
        node1 = ComputeNode(self)
        node2 = FileNode(self)
        scene.addItem(node1)
        scene.addItem(node2)
        node1.setPos(120, 120)
        node1.setPos(80, 80)


class MainWindow(QtWidgets.QMainWindow):

    def __init__(self, parent=None):

        super(MainWindow, self).__init__(parent)
        self.initUI()

    def initUI(self):

        menubar = self.menuBar()
        fileMenu = menubar.addMenu('File')

        impMenu = QtWidgets.QMenu('Import', self)
        impAct = QtWidgets.QAction('Import mail', self)
        impMenu.addAction(impAct)

        newAct = QtWidgets.QAction('New', self)

        fileMenu.addAction(newAct)
        fileMenu.addMenu(impMenu)

        self.horizontal = QtWidgets.QHBoxLayout()
        # Widgets for horizontal layout
        self.leftWidget = self._createTreeWidget()
        self.glWidget = GraphWidget(self)
        # self.rightWidget = self._createTextEditor()
        self.rightWidget = self._createParamWidget()
        # Add them
        self.horizontal.addWidget(self.leftWidget)
        self.horizontal.addWidget(self.glWidget)
        self.horizontal.addWidget(self.rightWidget)

        widget = QtWidgets.QWidget()
        widget.setLayout(self.horizontal)

        self.setCentralWidget(widget)

    def _createTreeWidget(self):
        treeWidget = QtWidgets.QTreeWidget()
        # treeWidget.setColumnCount(1)

        return treeWidget

    def _createTextEditor(self):
        textWidget = QtWidgets.QPlainTextEdit()

        return textWidget

    def _createParamWidget(self):
        widget = QtWidgets.QWidget()
        layout = QtWidgets.QVBoxLayout()
        layout.addWidget(QtWidgets.QLabel('Parameters'))
        layout.addStretch()
        layout.addWidget(QtWidgets.QLabel('stuff'))
        widget.setLayout(layout)

        return widget


if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)

    mw = MainWindow()
    mw.show()

    #widget = GraphWidget()
    # widget.show()

    sys.exit(app.exec_())
