#include <QApplication>
#include "CBForm.h"

int main(int argc, char *argv[]) {
    
	QApplication app(argc, argv);

	CBForm cb;
    // cb.resize(10, 310);
	cb.show();

    return app.exec();
	
}
