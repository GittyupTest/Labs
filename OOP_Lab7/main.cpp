#include "MainWindow.h"
#include "MapWidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MapWidget w;
    w.show();
    return a.exec();
}
