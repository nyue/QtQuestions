#include "AppMainWindow.h"
#include <QApplication>

#include <cstdlib>
#include <iostream>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
	
    AppMainWindow mw;
	
    mw.show();
	
    return app.exec();
	
}
