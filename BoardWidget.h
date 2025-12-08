#ifndef BOARDWIDGET_H
#define BOARDWIDGET_H
#include <QWidget>
#include <QVector>
#include <QGridLayout>
#include "CellButton.h"

class BoardWidget : public QWidget {
    Q_OBJECT
public:
    BoardWidget(int rows, int cols, QWidget* parent = nullptr);

    void setCellState(int row, int col, CellState state, int number = 0);
    CellButton* getCell(int row, int col) const;

    int rowsCount() const { return m_rows; }
    int colsCount() const { return m_cols; }

    void createGrid(int rows, int cols); // <-- make public

signals:
    void cellLeftClicked(int row, int col);
    void cellRightClicked(int row, int col);

private:
    int m_rows;
    int m_cols;
    QVector<QVector<CellButton*>> m_cells;
    QGridLayout* m_layout{nullptr};
};
#endif BOARDWIDGET_H
