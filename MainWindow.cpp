#include "MainWindow.h"
#include "WelcomeWindow.h"
#include <QMenuBar>
#include <QVBoxLayout>
#include <QMessageBox>

MainWindow::MainWindow(int rows, int cols, int mines, const QString& diffName, QWidget *parent)
    : QMainWindow(parent),
    rows(rows), cols(cols), mines(mines), elapsedSeconds(0),
    difficultyName(diffName)
{
    setWindowTitle(QString("Minesweeper %1 (%2x%3)").arg(difficultyName).arg(rows).arg(cols));
    setMinimumSize(cols * 25, rows * 25 + 100);
    setStyleSheet("background-color: #2c3e50; color: #ecf0f1;");

    QMenu *gameMenu = menuBar()->addMenu("Game");
    QAction *newGame = gameMenu->addAction("New Game");
    QAction *changeDifficulty = gameMenu->addAction("Change Difficulty");
    gameMenu->addSeparator();
    QAction *exitAct = gameMenu->addAction("Exit");

    connect(newGame, &QAction::triggered, this, &MainWindow::onNewGame);
    connect(changeDifficulty, &QAction::triggered, this, &MainWindow::onChangeDifficulty);
    connect(exitAct, &QAction::triggered, this, &MainWindow::onExit);

    menuBar()->addMenu("Help");

    QWidget *central = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(central);

    statusPanel = new StatusPanel(mines, difficultyName, this);
    connect(statusPanel, &StatusPanel::restartClicked, this, &MainWindow::onRestart);
    connect(statusPanel, &StatusPanel::backToMenuClicked, this, &MainWindow::onBackToMenu);

    layout->addWidget(statusPanel);
    layout->addStretch();
    setCentralWidget(central);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::onTimerTick);
    timer->start(1000);

    statusPanel->setFaceState(GameState::Playing);
}

void MainWindow::onTimerTick()
{
    elapsedSeconds++;
    statusPanel->updateTimer(elapsedSeconds);
}

void MainWindow::onNewGame()
{
    startNewGame(rows, cols, mines, difficultyName);
}

void MainWindow::onChangeDifficulty()
{
    emit backRequested();
}

void MainWindow::onExit()
{
    close();
}

void MainWindow::onRestart()
{
    elapsedSeconds = 0;
    statusPanel->updateTimer(elapsedSeconds);
    statusPanel->setFaceState(GameState::Playing);
}

void MainWindow::onBackToMenu()
{
    emit backRequested();
}

void MainWindow::startNewGame(int r, int c, int m, const QString& diffName)
{
    MainWindow *newGame = new MainWindow(r, c, m, diffName);
    newGame->show();
    this->close();
}
