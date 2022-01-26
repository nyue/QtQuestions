#include "ContextMenuMainWindow.h"
#include <QApplication>
#include <string>

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	
	ContextMenuMainWindow mw;
	
	mw.resize(1000, 600);
	mw.show();
	
	return app.exec();
}
