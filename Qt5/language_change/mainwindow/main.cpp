#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    
	QApplication app(argc, argv);

	MainWindow mw;
	mw.resize(600,400);
	mw.show();

	return app.exec();
}
