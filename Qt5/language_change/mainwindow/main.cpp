#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    
	QApplication app(argc, argv);
    MainWindow*  mw = new MainWindow();
    mw->resize(600,400);
    mw->show();

	return app.exec();
}
