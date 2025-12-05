#include "AppManager.h"
#include <QApplication>

AppManager::AppManager(QObject *parent)
    : QObject(parent), welcomeWindow(nullptr), gameWindow(nullptr)
{
}

void AppManager::start()
{
    welcomeWindow = new WelcomeWindow();
    welcomeWindow->show();

    connect(welcomeWindow, &WelcomeWindow::difficultySelected,
            this, &AppManager::onDifficultySelected);
}

void AppManager::onDifficultySelected(int rows, int cols, int mines)
{
    QString difficulty = (rows == 9 ? "Beginner" :
                              rows == 16 && cols == 16 ? "Intermediate" : "Expert");

    gameWindow = new MainWindow(rows, cols, mines, difficulty);
    gameWindow->show();

    welcomeWindow->hide();
    connect(gameWindow, &MainWindow::backRequested, this, &AppManager::onBackRequested);
}

void AppManager::onBackRequested()
{
    if (gameWindow)
    {
        gameWindow->close();
        delete gameWindow;
        gameWindow = nullptr;
    }

    if (welcomeWindow) welcomeWindow->show();
}
