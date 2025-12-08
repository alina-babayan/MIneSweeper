#include "StatusPanel.h"
#include <QHBoxLayout>
#include <QFont>

StatusPanel::StatusPanel(int mines, const QString& difficultyName, QWidget *parent)
    : QWidget(parent)
{
    setStyleSheet("background-color: #2c3e50; border-radius: 10px;");
    auto layout = new QHBoxLayout(this);
    layout->setContentsMargins(15, 5, 15, 5);
    layout->setSpacing(20);

    mineCounter = new QLCDNumber(3, this);
    mineCounter->setSegmentStyle(QLCDNumber::Flat);
    mineCounter->setStyleSheet("color: #e74c3c; background-color: #1a252f; border-radius:5px;");
    mineCounter->display(QString("%1").arg(mines, 3, 10, QChar('0')));

    restartBtn = new QPushButton("😊", this);
    restartBtn->setMinimumSize(50, 50);
    restartBtn->setMaximumSize(50, 50);
    restartBtn->setFont(QFont("Segoe UI", 20, QFont::Bold));
    restartBtn->setStyleSheet(
        "QPushButton { background-color: #3498db; color: #fff; border-radius: 25px; }"
        "QPushButton:hover { background-color: #5dade2; }"
        "QPushButton:pressed { background-color: #2980b9; }"
        );
    connect(restartBtn, &QPushButton::clicked, this, &StatusPanel::restartClicked);

    timer = new QLCDNumber(3, this);
    timer->setSegmentStyle(QLCDNumber::Flat);
    timer->setStyleSheet("color: #2ecc71; background-color: #1a252f; border-radius:5px;");
    timer->display("000");

    difficultyLabel = new QLabel(difficultyName, this);
    difficultyLabel->setStyleSheet("color: #f1c40f; font-weight: bold; font-size: 14px;");

    backBtn = new QPushButton("Back to Menu", this);
    backBtn->setStyleSheet(
        "QPushButton { color: #fff; background-color: #e67e22; border-radius: 12px; padding: 6px 12px; font-weight:bold; }"
        "QPushButton:hover { background-color: #d35400; }"
        "QPushButton:pressed { background-color: #ba4a00; }"
        );
    connect(backBtn, &QPushButton::clicked, this, &StatusPanel::backToMenuClicked);

    layout->addWidget(mineCounter);
    layout->addWidget(restartBtn);
    layout->addWidget(timer);
    layout->addWidget(difficultyLabel);
    layout->addStretch();
    layout->addWidget(backBtn);
}

void StatusPanel::setFaceState(GameState state)
{
    switch (state) {
    case GameState::Playing: restartBtn->setText("😊"); break;
    case GameState::Won:     restartBtn->setText("😎"); break;
    case GameState::Lost:    restartBtn->setText("💀"); break;
    }
}

void StatusPanel::updateMineCounter(int value)
{
    mineCounter->display(QString("%1").arg(value, 3, 10, QChar('0')));
}

void StatusPanel::updateTimer(int seconds)
{
    timer->display(QString("%1").arg(seconds, 3, 10, QChar('0')));
}

