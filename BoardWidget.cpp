#include "BoardWidget.h"
#include <QGridLayout>
#include <QDebug>

BoardWidget::BoardWidget(int rows, int cols, QWidget *parent)
    : QWidget(parent), rows(rows), cols(cols)
{
    createGrid(rows, cols);
}

void BoardWidget::createGrid(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;

    QGridLayout *grid = new QGridLayout(this);
    grid->setSpacing(3);
    grid->setContentsMargins(0, 0, 0, 0);

    buttons.clear();
    buttons.resize(rows, std::vector<CellButton*>(cols, nullptr));

    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < cols; ++c)
        {
            CellButton *cell = new CellButton(r, c, this);
            buttons[r][c] = cell;

            connect(cell, &CellButton::leftClicked, this, &BoardWidget::handleLeftClick);
            connect(cell, &CellButton::rightClicked, this, &BoardWidget::handleRightClick);

            grid->addWidget(cell, r, c);
        }
    }
    setLayout(grid);
}

CellButton* BoardWidget::getCell(int row, int col)
{
    if (row >= 0 && row < rows && col >= 0 && col < cols)
        return buttons[row][col];
    return nullptr;
}

void BoardWidget::handleLeftClick(int row, int col)
{
    qDebug() << "Left clicked:" << row << col;
    emit cellLeftClicked(row, col);
}

void BoardWidget::handleRightClick(int row, int col)
{
    qDebug() << "Right clicked:" << row << col;
    emit cellRightClicked(row, col);
}
