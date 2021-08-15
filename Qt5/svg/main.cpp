#include <QApplication>
#include <QPainterPath>
#include <QPainter>
#include <QMap>
#include <QDebug>
#include <QSvgGenerator>

int main(int argc, char **argv)
{
	QString path("nicholas.svg");
	
	QSvgGenerator generator;
    generator.setFileName(path);
    generator.setSize(QSize(200, 200));
    generator.setViewBox(QRect(0, 0, 200, 200));
    generator.setTitle("SVG Generator Example Drawing");
    generator.setDescription("An SVG drawing created by the SVG Generator "
							 "Example provided with Qt.");

	QPainter painter;
    painter.begin(&generator);
	painter.end();
}
