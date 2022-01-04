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

        self.actionFast.triggered.connect(self.Fast)
        self.actionSlow.triggered.connect(self.Slow)

        self.emptyWidget = QtWidgets.QWidget()
        self.verticalLayout.addWidget(QtWidgets.QLabel('Some header'))
        self.verticalLayout.addWidget(self.emptyWidget)
        self.verticalLayout.addWidget(QtWidgets.QLabel('Some footer'))
        self.verticalLayout.addStretch()

        self.slowWidget = QtWidgets.QLabel("Slow")
        # self.fastWidget = QtWidgets.QLabel("Fast")

        self.fastWidget = QtWidgets.QSlider(QtCore.Qt.Horizontal)
        self.fastWidget.setTickPosition(QtWidgets.QSlider.TicksAbove)
        self.fastWidget.setMinimum(-20)
        self.fastWidget.setMaximum(40)

    def Fast(self):
        itemToBeReplaced = self.verticalLayout.itemAt(1)
        if itemToBeReplaced:
            print('Fast')
            previousWidgetItem = self.verticalLayout.replaceWidget(
                itemToBeReplaced.widget(), self.fastWidget)
            if previousWidgetItem:
                previousWidgetItem.widget().setVisible(False)
                self.fastWidget.setVisible(True)

    def Slow(self):
        itemToBeReplaced = self.verticalLayout.itemAt(1)
        if itemToBeReplaced:
            print('Slow')
            previousWidgetItem = self.verticalLayout.replaceWidget(
                itemToBeReplaced.widget(), self.slowWidget)
            if previousWidgetItem:
                previousWidgetItem.widget().setVisible(False)
                self.slowWidget.setVisible(True)


app = QtWidgets.QApplication(sys.argv)

window = MainWindow()
window.show()
app.exec_()
