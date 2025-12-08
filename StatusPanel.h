#ifndef STATUSPANEL_H
#define STATUSPANEL_H

#include <QWidget>
#include <QLCDNumber>
#include <QPushButton>
#include <QLabel>
enum class GameState {
    Playing,
    Won,
    Lost
};
class StatusPanel : public QWidget
{
    Q_OBJECT
public:
    explicit StatusPanel(int mines, const QString& difficultyName, QWidget *parent = nullptr);

    void setFaceState(GameState state);
    void updateMineCounter(int value);
    void updateTimer(int seconds);

signals:
    void restartClicked();
    void backToMenuClicked();

private:
    QLCDNumber *mineCounter;
    QPushButton *restartBtn;
    QLCDNumber *timer;
    QLabel *difficultyLabel;
    QPushButton *backBtn;
};

#endif  STATUSPANEL_H
