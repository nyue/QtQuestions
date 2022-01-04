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

        self.actionAdd.triggered.connect(self.Add)
        self.actionClear.triggered.connect(self.Clear)

        vlayout = self.findChild(QtWidgets.QVBoxLayout, "verticalLayout")
        # vlayout.addWidget(QtWidgets.QLabel("Parameters"))

    def Add(self):
        print('Adding')
        self.verticalLayout.addWidget(QtWidgets.QLabel("Adding"))

    def Remove(self):
        print('Remove')
        child = self.verticalLayout.takeAt(0)
        if child:
            self.verticalLayout.removeItem(child)
            del child
            self.verticalLayout.update()

    def Clear(self):
        print('Clear number of widgets = {}'.format(self.verticalLayout.count()))
        child = self.verticalLayout.takeAt(0)
        while child:
            self.verticalLayout.removeItem(child)
            del child
            child = self.verticalLayout.takeAt(0)
        self.verticalLayout.update()

app = QtWidgets.QApplication(sys.argv)

window = MainWindow()
window.show()
app.exec_()

