#include "MyMainWindow.h"
#include <QApplication>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    MyMainWindow mw;

    mw.show();

    return app.exec();

}
