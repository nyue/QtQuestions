import sys
from PySide2 import QtWidgets, QtGui, QtCore

from MainWindow import Ui_MainWindow


class MainWindow(QtWidgets.QMainWindow, Ui_MainWindow):
    def __init__(self):
        super(MainWindow, self).__init__()
        self.setupUi(self)

        # Further location UI customization
        self.actionQuit.setShortcut(QtGui.QKeySequence.Quit)
        self.actionQuit.triggered.connect(self.close)

        self.contextMenu = self._createContextMenu()

    def _createContextMenu(self):
        menu = QtWidgets.QMenu(self)
        imageMenu = menu.addMenu("Image")
        readerAction = imageMenu.addAction("PNGReader")
        writerAction = imageMenu.addAction("PNGWriter")
        geometryMenu = menu.addMenu("Geometry")
        objLoaderAction = geometryMenu.addAction("OBJLoader")
        objWriterAction = geometryMenu.addAction("OBJWriter")
        #quitAction = menu.addAction("Quit")
        #quitAction.triggered.connect(self.close)

        # C++ version : https://stackoverflow.com/questions/42522136/qaction-triggered-signal-to-pass-parameter-to-slot
        # connect(copyDataAction, &QAction::triggered, this, [=](){
        # CopyTableData(DataTable);
        # });

        # PySide2 implementation : https://www.pythonguis.com/tutorials/pyside-transmitting-extra-data-qt-signals/
        readerAction.triggered.connect(lambda x: self.createInstance('RNGReader'))
        writerAction.triggered.connect(lambda x: self.createInstance('RNGWriter'))

        objLoaderAction.triggered.connect(lambda x: self.createInstance('OBJLoader'))
        objWriterAction.triggered.connect(lambda x: self.createInstance('OBJWriter'))

        return menu

    def contextMenuEvent(self, event: QtGui.QContextMenuEvent) -> None:
        # print('MainWindow contextMenuEvent()')
        action = self.contextMenu.exec_(self.mapToGlobal(event.pos()))
        # print(self.actionMap[action])
        # super(MainWindow, self).contextMenuEvent(event)

    def createInstance(self, classname:str):
        print('Create instance of {}'.format(classname))

app = QtWidgets.QApplication(sys.argv)

window = MainWindow()
window.show()
app.exec_()
