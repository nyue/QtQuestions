#include "anothermenu.h"
#include <QMenu>
#include <QMenuBar>

AnotherMenu::AnotherMenu(QWidget *parent)
: QMainWindow(parent)
{
	// Without the following line, the menubar does not show up on OS X
  menuBar()->setNativeMenuBar(false);
  QAction *quit = new QAction("&Quit", this);
  QAction *open = new QAction("&Open", this);
  QAction *close = new QAction("&Close", this);

  QMenu *file;
  file = menuBar()->addMenu("&File");
  file->addAction(open);
  file->addAction(close);
  file->addSeparator();
  file->addAction(quit);

  QAction *about = new QAction("&About", this);

  QMenu *help;
  help = menuBar()->addMenu("&Help");
  help->addAction(about);

  connect(quit, &QAction::triggered, qApp, QApplication::quit);
}
