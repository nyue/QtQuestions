#include <QApplication>
#include "MLIMainWindow.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    MLIMainWindow mw;

    mw.show();

    return app.exec();

}
