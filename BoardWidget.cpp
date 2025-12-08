#include "BoardWidget.h"
#include <QMouseEvent>

BoardWidget::BoardWidget(int rows, int cols, QWidget* parent)
    : QWidget(parent), m_rows(rows), m_cols(cols)
{
    createGrid(rows, cols);
}

void BoardWidget::createGrid(int rows, int cols)
{
    if (m_layout) delete m_layout;

    m_layout = new QGridLayout(this);
    m_layout->setSpacing(1);

    m_cells.resize(rows);
    for (int r = 0; r < rows; ++r) {
        m_cells[r].resize(cols);
        for (int c = 0; c < cols; ++c) {
            CellButton* btn = new CellButton(r, c, this);
            m_cells[r][c] = btn;
            m_layout->addWidget(btn, r, c);

            connect(btn, &QPushButton::clicked, [this, r, c]() {
                emit cellLeftClicked(r, c);
            });
            btn->setContextMenuPolicy(Qt::CustomContextMenu);
            connect(btn, &QPushButton::customContextMenuRequested, [this, r, c](const QPoint&){
                emit cellRightClicked(r, c);
            });
        }
    }
}

void BoardWidget::setCellState(int row, int col, CellState state, int number)
{
    if (row < 0 || row >= m_rows || col < 0 || col >= m_cols) return;
    m_cells[row][col]->setState(state, number);
}

CellButton* BoardWidget::getCell(int row, int col) const
{
    if (row < 0 || row >= m_rows || col < 0 || col >= m_cols) return nullptr;
    return m_cells[row][col];
}
