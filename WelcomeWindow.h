#ifndef WELCOMEWINDOW_H
#define WELCOMEWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>

class WelcomeWindow : public QMainWindow
{
    Q_OBJECT

public:
     WelcomeWindow(QWidget *parent = nullptr);
    ~WelcomeWindow();

signals:
    void difficultySelected(int rows, int cols, int mines);

private:
    QLabel* title;
    QLabel* chooseDiff;
    QPushButton* begin;
    QPushButton* intermed;
    QPushButton* expert;
    QPushButton* howToPlay;
    QPushButton* about;

    void setupUI();
    void setupConnections();
};

#endif // WELCOMEWINDOW_H
