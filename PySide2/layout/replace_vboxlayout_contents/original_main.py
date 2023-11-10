from PySide2.QtWidgets import QApplication, QWidget, QVBoxLayout, QPushButton

class MyWidget(QWidget):
    def __init__(self):
        super().__init__()

        self.layout = QVBoxLayout(self)

        # Initial widgets
        self.button1 = QPushButton('Button 1')
        self.button2 = QPushButton('Button 2')
        self.layout.addWidget(self.button1)
        self.layout.addWidget(self.button2)

        # Replace widgets
        self.replace_widgets()

    def replace_widgets(self):
        # Remove existing widgets from the layout
        for i in reversed(range(self.layout.count())):
            widget = self.layout.takeAt(i).widget()
            if widget is not None:
                widget.setParent(None)

        # Add new widgets
        self.button3 = QPushButton('Button 3')
        self.button4 = QPushButton('Button 4')
        self.layout.addWidget(self.button3)
        self.layout.addWidget(self.button4)

if __name__ == '__main__':
    app = QApplication([])

    window = MyWidget()
    window.show()

    app.exec_()
