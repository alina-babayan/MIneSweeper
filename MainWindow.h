#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "StatusPanel.h"
#include "BoardWidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(int rows, int cols, int mines, const QString& difficultyName = "Beginner", QWidget *parent = nullptr);

signals:
    void backRequested();

private slots:
    void onTimerTick();
    void onNewGame();
    void onChangeDifficulty();
    void onExit();
    void onRestart();
    void onBackToMenu();
    void handleCellLeftClicked(int row, int col);
    void handleCellRightClicked(int row, int col);

private:
    int rows;
    int cols;
    int mines;
    int elapsedSeconds;
    QString difficultyName;

    QTimer *timer;
    StatusPanel *statusPanel;
    BoardWidget *boardWidget;

    void startNewGame(int r, int c, int m, const QString& diffName);
};

#endif // MAINWINDOW_H
