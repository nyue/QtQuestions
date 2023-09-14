import sys
from PySide2 import QtWidgets
from MainWindow import Ui_MainWindow


class MyMainWindow(QtWidgets.QMainWindow, Ui_MainWindow):
    def __init__(self):
        super(MyMainWindow, self).__init__()
        self.setupUi(self)

        self.actionQuit.triggered.connect(QtWidgets.QApplication.instance().quit)
        self.actionAbout_Plugins.setMenuRole(QtWidgets.QAction.MenuRole.AboutQtRole)
        self.actionAbout_Plugins.triggered.connect(self.about_Plugins)

    def about_Plugins(self):
        print('Plugins')

app = QtWidgets.QApplication(sys.argv)

window = MyMainWindow()
window.show()
app.exec_()
