#include <QApplication>
#include "IOMainWindow.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    IOMainWindow mw;

    mw.show();

    return app.exec();

}
