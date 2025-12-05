#include "WelcomeWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QFont>

WelcomeWindow::WelcomeWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget* central = new QWidget(this);
    setCentralWidget(central);

    setupUI();
    setupConnections();

    setWindowTitle("Minesweeper — Welcome");
    setFixedSize(450, 520);
}

void WelcomeWindow::setupUI()
{
    this->setStyleSheet("QMainWindow { background-color: #2c3e50; }");

    QFont titleFont("Segoe UI", 28, QFont::Bold);
    QFont subtitleFont("Segoe UI", 16);
    QFont buttonFont("Segoe UI", 14, QFont::Bold);

    title = new QLabel("Minesweeper", this);
    title->setFont(titleFont);
    title->setAlignment(Qt::AlignCenter);
    title->setStyleSheet("color: #ecf0f1;");

    chooseDiff = new QLabel("Choose Difficulty", this);
    chooseDiff->setFont(subtitleFont);
    chooseDiff->setAlignment(Qt::AlignCenter);
    chooseDiff->setStyleSheet("color: #bdc3c7;");

    begin = new QPushButton("Beginner\n 9 × 9  10 mines", this);
    begin->setFont(buttonFont);
    begin->setMinimumSize(200, 60);
    begin->setStyleSheet(
        "QPushButton { color: #ecf0f1; background-color: #34495e; border-radius: 12px; }"
        "QPushButton:hover { background-color: #5d6d7e; }"
        "QPushButton:pressed { background-color: #1abc9c; }"
        );

    intermed = new QPushButton("Intermediate\n 16 × 16  40 mines", this);
    intermed->setFont(buttonFont);
    intermed->setMinimumSize(200, 60);
    intermed->setStyleSheet(
        "QPushButton { color: #ecf0f1; background-color: #34495e; border-radius: 12px; }"
        "QPushButton:hover { background-color: #5d6d7e; }"
        "QPushButton:pressed { background-color: #1abc9c; }"
        );

    expert = new QPushButton("Expert\n 16 × 30  99 mines", this);
    expert->setFont(buttonFont);
    expert->setMinimumSize(200, 60);
    expert->setStyleSheet(
        "QPushButton { color: #ecf0f1; background-color: #34495e; border-radius: 12px; }"
        "QPushButton:hover { background-color: #5d6d7e; }"
        "QPushButton:pressed { background-color: #1abc9c; }"
        );

    howToPlay = new QPushButton("How To Play", this);
    howToPlay->setFont(subtitleFont);
    howToPlay->setMinimumSize(160, 45);
    howToPlay->setStyleSheet(
        "QPushButton { color: #2c3e50; background-color: #ecf0f1; border-radius: 10px; }"
        "QPushButton:hover { background-color: #d0d3d4; }"
        "QPushButton:pressed { background-color: #b0b7b7; }"
        );

    about = new QPushButton("About", this);
    about->setFont(subtitleFont);
    about->setMinimumSize(160, 45);
    about->setStyleSheet(
        "QPushButton { color: #2c3e50; background-color: #ecf0f1; border-radius: 10px; }"
        "QPushButton:hover { background-color: #d0d3d4; }"
        "QPushButton:pressed { background-color: #b0b7b7; }"
        );

    QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget());
    mainLayout->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(title);
    mainLayout->addWidget(chooseDiff);
    mainLayout->addSpacing(25);
    mainLayout->addWidget(begin);
    mainLayout->addWidget(intermed);
    mainLayout->addWidget(expert);
    mainLayout->addSpacing(20);

    QHBoxLayout* bottomLayout = new QHBoxLayout();
    bottomLayout->addWidget(howToPlay);
    bottomLayout->addSpacing(20);
    bottomLayout->addWidget(about);

    mainLayout->addLayout(bottomLayout);
}

void WelcomeWindow::setupConnections()
{
    connect(begin, &QPushButton::clicked, this, [this](){
        emit difficultySelected(9, 9, 10);
    });

    connect(intermed, &QPushButton::clicked, this, [this](){
        emit difficultySelected(16, 16, 40);
    });

    connect(expert, &QPushButton::clicked, this, [this](){
        emit difficultySelected(16, 30, 99);
    });
    connect(howToPlay, &QPushButton::clicked, this, [this](){
        QMessageBox::information(this, "How to Play",
                                 "• Click to reveal tiles\n"
                                 "• Right-click to place/remove flags\n"
                                 "• Numbers indicate adjacent mines\n"
                                 "• Clear all non-mine tiles to win\n"
                                 "• Avoid clicking a mine!");
    });

    connect(about, &QPushButton::clicked, this, [this](){
        QMessageBox::about(this, "About Minesweeper",
                           "Minesweeper Qt6\n\nDeveloped by: Alina Babayan");
    });
}

WelcomeWindow::~WelcomeWindow() {}
