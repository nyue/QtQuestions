#include "anothermenu.h"
#include "util.h"

int main(int argc, char *argv[]) {

  QApplication app(argc, argv);  
    
  AnotherMenu window;

  std::string name;
  somefunction(name);
  
  window.resize(250, 150);
  window.setWindowTitle("Another menu");
  window.show();

  return app.exec();
}
