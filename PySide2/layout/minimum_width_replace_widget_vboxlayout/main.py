import sys
from PySide2 import QtWidgets, QtGui, QtCore

from MainWindow import Ui_MainWindow


class MainWindow(QtWidgets.QMainWindow, Ui_MainWindow):
    def __init__(self):
        super(MainWindow, self).__init__()
        self.setupUi(self)

        # Further location UI customization
        self.actionQuit.setShortcut(QtGui.QKeySequence.Quit)
        self.actionQuit.triggered.connect(self.close)

        self.actionPopulate1.triggered.connect(self.populate1)
        self.actionPopulate2.triggered.connect(self.populate2)

        replaceableWidget = self.findChild(
            QtWidgets.QWidget, "replaceableWidget")
        assert(replaceableWidget)

        self.ui1 = self.createUI_1()
        self.ui2 = self.createUI_2()

    def populate1(self):
        vlayout = self.findChild(QtWidgets.QVBoxLayout, "verticalLayout")
        assert(vlayout)
        print('Populate 1 : count = {}'.format(vlayout.count()))
        itemAt1 = vlayout.itemAt(1)
        assert(itemAt1)
        vlayout.replaceWidget(itemAt1.widget(),self.ui1)
        itemAt1.widget().setVisible(False)
        self.ui1.setVisible(True)

    def populate2(self):
        vlayout = self.findChild(QtWidgets.QVBoxLayout, "verticalLayout")
        assert(vlayout)
        print('Populate 1 : count = {}'.format(vlayout.count()))
        itemAt1 = vlayout.itemAt(1)
        assert(itemAt1)
        vlayout.replaceWidget(itemAt1.widget(),self.ui2)
        itemAt1.widget().setVisible(False)
        self.ui2.setVisible(True)

    def createUI_1(self):
        widget = QtWidgets.QWidget()
        vlayout = QtWidgets.QVBoxLayout(widget)
        vlayout.addWidget(QtWidgets.QLabel("Set 1 - START"))
        slider = QtWidgets.QSlider(QtCore.Qt.Horizontal)
        slider.valueChanged.connect(self.handler1)
        vlayout.addWidget(slider)
        vlayout.addWidget(QtWidgets.QLabel("Set 1 - END"))
        return widget

    def createUI_2(self):
        widget = QtWidgets.QWidget()
        vlayout = QtWidgets.QVBoxLayout(widget)
        vlayout.addWidget(QtWidgets.QLabel("Set 2 - START"))
        slider = QtWidgets.QSlider()
        slider.valueChanged.connect(self.handler2)
        vlayout.addWidget(slider)
        vlayout.addWidget(QtWidgets.QLabel("Set 2 - END"))
        return widget

    def handler1(self):
        print('handler 1')

    def handler2(self):
        print('handler 2')

app = QtWidgets.QApplication(sys.argv)

window = MainWindow()
window.show()
app.exec_()
