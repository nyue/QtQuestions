import sys
from PySide2 import QtWidgets, QtGui, QtCore

from main_window import Ui_MainWindow


class MainWindow(QtWidgets.QMainWindow, Ui_MainWindow):
    def __init__(self):
        super(MainWindow, self).__init__()
        self.setupUi(self)

        # Further location UI customization
        self.actionQuit.setShortcut(QtGui.QKeySequence.Quit)
        self.actionQuit.triggered.connect(self.close)

        # Provide a layout to the content (ensures always exists and reusable)
        self.layout = QtWidgets.QVBoxLayout()
        self.scrollAreaWidgetContents.setLayout(self.layout)
        # for use later
        self.verticalSpacer = QtWidgets.QSpacerItem(20, 40, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)

        self.actionOptionA.triggered.connect(self.OptionA)
        self.actionOptionB.triggered.connect(self.OptionB)
        self.actionClear.triggered.connect(self.Clear)

    def replace_widgets(self, names: list):
        # Remove existing widgets from the layout
        self.Clear()

        # Add new widgets
        for name in names:
            self.layout.addWidget(QtWidgets.QLabel(name))

        # Adding a space LAST is important for the widget to be packed from top
        self.layout.addItem(self.verticalSpacer)

    def OptionA(self):
        print('OptionA')
        self.replace_widgets(['Option A (1)', 'Option A (2)'])

    def OptionB(self):
        print('OptionB')
        self.replace_widgets(['Option B (X)', 'Option B (Y)', 'Option B (Z)'])

    def Clear(self):
        print('Clear')
        for i in reversed(range(self.layout.count())):
            widget = self.layout.takeAt(i).widget()
            if widget is not None:
                widget.setParent(None)


app = QtWidgets.QApplication(sys.argv)

window = MainWindow()
window.show()
app.exec_()
