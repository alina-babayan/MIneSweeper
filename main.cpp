#include <QApplication>
#include "AppManager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    AppManager manager;
    manager.start();

    return a.exec();
}
