#include <QApplication>
#include "UGIMainWindow.h"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    UGIMainWindow mw;

    mw.show();

    return app.exec();

}
