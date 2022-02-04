#include "MyMainWindow.h"
//
#include <QApplication>
//
#include <boost/program_options.hpp>
#include <boost/format.hpp>
// #include <stdexcept>
#include <string>
#include <iostream>

int main(int argc, char** argv)
{

		QApplication app(argc, argv);

		MyMainWindow mw;

		mw.resize(1000, 600);
		mw.show();

		return app.exec();
}
