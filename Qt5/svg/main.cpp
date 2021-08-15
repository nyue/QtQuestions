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
    QColor thrusterColor = Qt::green;
    painter.begin(&generator);

    QPen pen(thrusterColor,4);
    painter.setPen(pen);
    QPainterPath p1;

	// Outer loop (Counter clockwise)
    p1.moveTo(20,10);
    p1.quadTo(QPointF( 10, 10 ),  QPointF( 10, 20  ));
    p1.lineTo(QPointF( 10, 180 ));
    p1.quadTo(QPointF( 10, 190 ), QPointF( 20, 190 ));
    p1.lineTo(QPointF( 180, 190 ));
    p1.quadTo(QPointF( 190, 190 ), QPointF( 190, 180 ));
    p1.lineTo(QPointF( 190, 20 ));
    p1.quadTo(QPointF( 190, 10 ), QPointF( 180, 10 ));

	// Inner loop (Clockwise)
    p1.moveTo(50,60);
    p1.quadTo(QPointF( 50, 50 ), QPointF( 60, 50 ) );
    p1.lineTo(QPointF( 140, 50 ));
    p1.quadTo(QPointF( 150, 50 ), QPointF( 150, 60 ) );
    p1.lineTo(QPointF( 150, 140 ));
    p1.quadTo(QPointF( 150, 150 ), QPointF( 140, 150 ) );
    p1.lineTo(QPointF( 60, 150 ));
    p1.quadTo(QPointF( 50, 150 ), QPointF( 50, 140 ) );

    painter.fillPath(p1, thrusterColor);

    painter.end();
}
