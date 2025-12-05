#include "CellButton.h"
#include <QDebug>

CellButton::CellButton(int row, int col, QWidget *parent)
    : QPushButton(parent), row(row), col(col)
{
    setFixedSize(30, 30);
    setStyleSheet("background-color: #7f8c8d; border: 1px solid #2c3e50;");
}

void CellButton::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        emit leftClicked(row, col);
    }
    else if (event->button() == Qt::RightButton)
    {
        emit rightClicked(row, col);
    }
    QPushButton::mousePressEvent(event);
}
