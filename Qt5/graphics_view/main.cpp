#include <QApplication>
#include "GVMainWindow.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    GVMainWindow mw;

    mw.show();

    return app.exec();

}
