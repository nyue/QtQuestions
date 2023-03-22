#include "MyMainWindow.h"
#include "util.h"
#include <QApplication>

int main(int argc, char** argv)
{
	int result = myfunction();
	
    QApplication app(argc, argv);

    MyMainWindow mw;

    mw.show();

    return app.exec();

}
