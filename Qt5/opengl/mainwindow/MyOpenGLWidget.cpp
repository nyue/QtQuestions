#include "MyOpenGLWidget.h"

MyOpenGLWidget::MyOpenGLWidget(QWidget *parent)
{
}

MyOpenGLWidget::~MyOpenGLWidget()
{
}

void MyOpenGLWidget::initializeGL()
{
    qDebug() << "initializeGL";
}

void MyOpenGLWidget::paintGL()
{
    qDebug() << "paintGL";

}

void MyOpenGLWidget::resizeGL(int width, int height)
{
    qDebug() << "resizeGL";

}

void MyOpenGLWidget::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "mousePressEvent";

}

void MyOpenGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() << "mouseMoveEvent";

}
