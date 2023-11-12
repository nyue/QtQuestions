import sys
from PySide2 import QtWidgets, QtGui, QtCore

from main_window import Ui_MainWindow
from override_name_type_dialog import Ui_Dialog


class TypesDialog(Ui_Dialog, QtWidgets.QDialog):
    """Types dialog."""

    def __init__(self, parent=None):
        super().__init__(parent)
        # Run the .setupUi() method to show the GUI
        self.setupUi(self)

        return self.typesComboBox.addItems(['String','Integer','Boolean'])

    def getName(self):
        return self.nameLineEdit.text()

    def getType(self):
        return self.typesComboBox.currentText()

class MainWindow(QtWidgets.QMainWindow, Ui_MainWindow):
    def __init__(self):
        super(MainWindow, self).__init__()
        self.setupUi(self)

        self.addButton.clicked.connect(self.on_add_button_clicked)
        self.deleteButton.clicked.connect(self.on_delete_button_clicked)

        # Layout for content area
        self.contentLayout = QtWidgets.QVBoxLayout()
        self.scrollAreaWidgetContents.setLayout(self.contentLayout)
        # for use later
        self.verticalSpacer = QtWidgets.QSpacerItem(
            20, 40, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)

        # Some data
        self.inputTypes = {}  # { <name> : <type> }

    def on_add_button_clicked(self):
        print("Add button clicked!")
        dlg = TypesDialog(self)
        if dlg.exec() == 1:
            name = dlg.getName()
            type = dlg.getType()
            print((name,type))

    def on_delete_button_clicked(self):
        print("Delete button clicked!")


app = QtWidgets.QApplication(sys.argv)

window = MainWindow()
window.show()
app.exec_()
