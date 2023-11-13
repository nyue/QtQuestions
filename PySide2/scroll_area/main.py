import sys
from PySide2 import QtWidgets, QtGui, QtCore

from main_window import Ui_MainWindow


class MainWindow(QtWidgets.QMainWindow, Ui_MainWindow):
    def __init__(self):
        super(MainWindow, self).__init__()
        self.setupUi(self)

        self.addPushButton.clicked.connect(self.on_add_button_clicked)
        self.deletePushButton.clicked.connect(self.on_delete_button_clicked)
        self.clearPushButton.clicked.connect(self.on_clear_button_clicked)
        self.statusPushButton.clicked.connect(self.on_status_button_clicked)

        # Create a list widget to contain the list items
        self.list_widget = QtWidgets.QListWidget()

        # connect itemClicked to Clicked method
        self.list_widget.itemClicked.connect(self.list_item_clicked)

        # Add some items to the list widget (you can replace this with your items)
        for i in range(40):
            item = QtWidgets.QListWidgetItem(f"Item {i+1}")
            self.list_widget.addItem(item)

        # Set the list widget as the widget for the scroll area
        self.scrollArea.setWidget(self.list_widget)

    def debug_print_selected(self):
        pass

    def on_add_button_clicked(self):
        print("Add button clicked!")
        self.list_widget.addItem("Nicholas")

    def on_delete_button_clicked(self):
        print("Delete button clicked!")

    def on_clear_button_clicked(self):
        print("Clear button clicked!")
        # find selected, if none, do nothing
        self.list_widget.clearSelection()

    def on_status_button_clicked(self):
        print("Status button clicked!")
        # find selected, if none, do nothing
        print(self.list_widget.selectedItems())

    def list_item_clicked(self, item):
        print(item.text())

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
