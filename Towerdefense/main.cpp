//#include "mainwindow.h"
#include "start.h"      //开始场景
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    start w;
    w.show();

    return a.exec();
}
