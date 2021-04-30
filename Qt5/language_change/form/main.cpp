#include "Form.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    
	QApplication app(argc, argv);

	Form f;
	f.resize(600,400);
	f.show();

	return app.exec();
}
