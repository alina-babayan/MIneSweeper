#include <QApplication>
#include "WelcomeWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    WelcomeWindow welcome;
    welcome.show();

    return app.exec();
}
