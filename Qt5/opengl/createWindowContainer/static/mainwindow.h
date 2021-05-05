#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QOpenGLWindow>
#include <QResizeEvent>
#include <QTimer>

class MyOpenGLWindow : public QOpenGLWindow
{
    Q_OBJECT;

public:
    explicit MyOpenGLWindow(UpdateBehavior updateBehavior = NoPartialUpdate, QWindow *parent = 0) :
        QOpenGLWindow(updateBehavior, parent)
    {
    }

    virtual void paintGL() override
    {
        glClearColor(1.0, 0.0, 0.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void setMainWindow(QMainWindow *mw)
    {
        m_mainWindow = mw;
    }

private:
    bool m_hasMouse = false;
    QPoint m_pressOrigin;
    QSize m_pressSize;

    QMainWindow *m_mainWindow;

    virtual void mousePressEvent(QMouseEvent *e) override
    {
        m_hasMouse = true;
        m_pressOrigin = e->pos();
        m_pressSize = m_mainWindow->size();
    }

    virtual void mouseReleaseEvent(QMouseEvent *e) override
    {
        m_hasMouse = false;
    }

    virtual void mouseMoveEvent(QMouseEvent *e) override
    {
        if(m_hasMouse)
        {
            int deltaX = e->pos().x() - m_pressOrigin.x();
            int deltaY = e->pos().y() - m_pressOrigin.y();

            QSize sz;

            sz.setWidth(m_pressSize.width() + deltaX);
            sz.setHeight(m_pressSize.height() + deltaY);

            m_mainWindow->resize(sz);
        }
    }
};


namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    MyOpenGLWindow *m_myWindow;
};

#endif // MAINWINDOW_H
