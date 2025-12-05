#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "StatusPanel.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(int rows, int cols, int mines, const QString& difficultyName = "Beginner", QWidget *parent = nullptr);

signals:
    void backRequested();  // <-- սիգնալ back-ի համար

private slots:
    void onTimerTick();
    void onNewGame();
    void onChangeDifficulty();
    void onExit();
    void onRestart();
    void onBackToMenu();

private:
    int rows;
    int cols;
    int mines;
    int elapsedSeconds;
    QString difficultyName;

    QTimer *timer;
    StatusPanel *statusPanel;

    void startNewGame(int r, int c, int m, const QString& diffName);
};

#endif // MAINWINDOW_H
