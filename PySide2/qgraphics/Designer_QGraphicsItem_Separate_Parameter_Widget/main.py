import sys
from PySide2 import QtWidgets

from MainWindow import Ui_MainWindow


class MainWindow(QtWidgets.QMainWindow, Ui_MainWindow):
    def __init__(self):
        super(MainWindow, self).__init__()
        self.setupUi(self)

        # Further location UI customization
        vlayout = self.findChild(QtWidgets.QVBoxLayout, "verticalLayout")
        vlayout.addWidget(QtWidgets.QLabel("Parameters"))

app = QtWidgets.QApplication(sys.argv)

window = MainWindow()
window.show()
app.exec_()
