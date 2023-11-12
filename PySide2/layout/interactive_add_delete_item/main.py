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

        return self.typesComboBox.addItems(['String', 'Integer', 'Boolean'])

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
        self.contentLayout.addItem(self.verticalSpacer)

        # Some data
        self.inputTypes = {}  # { <name> : <type> }

    def on_add_button_clicked(self):
        print("Add button clicked!")
        dlg = TypesDialog(self)
        if dlg.exec() == 1:
            name = dlg.getName()
            type = dlg.getType()
            if name in self.inputTypes:
                error_dialog = QtWidgets.QErrorMessage(self)
                error_dialog.showMessage('Name already exists')
            else:
                self.inputTypes[name] = type
                button = QtWidgets.QPushButton(name, self)
                button.clicked.connect(self.nameButtonClick)
                self.contentLayout.insertWidget(0, button)

    def on_delete_button_clicked(self):
        print("Delete button clicked!")
        # find selected, if none, do nothing

    def nameButtonClick(self):
        sender = self.sender()
        if isinstance(sender, QtWidgets.QPushButton):
            for i in range(self.contentLayout.count()-1):
                item = self.contentLayout.itemAt(i).widget()
                item.setFont(self.font())  # Reset font to default
            label_font = sender.font()
            label_font.setBold(True)
            sender.setFont(label_font)


app = QtWidgets.QApplication(sys.argv)

window = MainWindow()
window.show()
app.exec_()
