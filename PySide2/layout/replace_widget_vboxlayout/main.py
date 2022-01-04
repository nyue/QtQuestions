import sys
from PySide2 import QtWidgets, QtGui

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
        self.verticalLayout.addWidget(self.emptyWidget)

        self.slowWidget = QtWidgets.QLabel("Slow")
        self.fastWidget = QtWidgets.QLabel("Fast")

    def Fast(self):
        print('Fast')
        itemToBeReplaced = self.verticalLayout.itemAt(0)
        if itemToBeReplaced:
            self.verticalLayout.replaceWidget(itemToBeReplaced.widget(),self.fastWidget)
            self.verticalLayout.update()

    def Slow(self):
        print('Slow')
        itemToBeReplaced = self.verticalLayout.itemAt(0)
        if itemToBeReplaced:
            self.verticalLayout.replaceWidget(itemToBeReplaced.widget(),self.slowWidget)
            self.verticalLayout.update()

app = QtWidgets.QApplication(sys.argv)

window = MainWindow()
window.show()
app.exec_()

