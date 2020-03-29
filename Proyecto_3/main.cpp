#include "mainwindow.h"
#include <QApplication>
#include <zip.h>

int main(int argc, char *argv[])
{

      QApplication a(argc, argv);
     DrawnWindow w;
     w.show();
     return a.exec();


}
