from PySide2 import QtWidgets


class Test:
    def __init__(self):
        self.window = QtWidgets.QMainWindow()
        self.mainWidget = QtWidgets.QWidget()
        self.window.setCentralWidget(self.mainWidget)
        self.vertical_layout_main = QtWidgets.QVBoxLayout(self.mainWidget)
        scroll = QtWidgets.QScrollArea()

        content_widget = QtWidgets.QWidget()
        scroll.setWidget(content_widget)
        scroll.setWidgetResizable(True)

        lay = QtWidgets.QVBoxLayout(content_widget)

        for l in "ABCDEFGHIJKLMNOPQRSTUVWXYZ":
            btn = QtWidgets.QPushButton(l)
            lay.addWidget(btn)
        lay.addStretch()

        scroll.setFixedHeight(400)

        self.vertical_layout_main.addWidget(scroll)
        self.window.show()


class TestNew:
    def __init__(self):
        self.window = QtWidgets.QMainWindow()
        self.mainWidget = QtWidgets.QWidget()
        self.window.setCentralWidget(self.mainWidget)
        self.vertical_layout_main = QtWidgets.QVBoxLayout(self.mainWidget)

        nested0 = self.nestedLayout("ABCDEF")
        nested1 = self.nestedLayout("GHIJKL")
        self.vertical_layout_main.addWidget(nested1)
        self.vertical_layout_main.addWidget(nested0)
        self.window.show()

    def nestedLayout(self,content_string):
        content_widget = QtWidgets.QWidget()

        lay = QtWidgets.QVBoxLayout(content_widget)

        for l in content_string:
            btn = QtWidgets.QPushButton(l)
            lay.addWidget(btn)

        return content_widget

if __name__ == '__main__':
    import sys
    app = QtWidgets.QApplication(sys.argv)
    t = TestNew()
    sys.exit(app.exec_())
