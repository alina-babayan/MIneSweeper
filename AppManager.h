#ifndef APPMANAGER_H
#define APPMANAGER_H

#include <QObject>
#include "WelcomeWindow.h"
#include "MainWindow.h"

class AppManager : public QObject
{
    Q_OBJECT
public:
    explicit AppManager(QObject *parent = nullptr);
    void start();

private slots:
    void onDifficultySelected(int rows, int cols, int mines);
    void onBackRequested();

private:
    WelcomeWindow *welcomeWindow;
    MainWindow *gameWindow;
};

#endif // APPMANAGER_H
