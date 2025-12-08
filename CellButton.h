#ifndef CELLBUTTON_H
#define CELLBUTTON_H

#include <QPushButton>
#include <QFont>

enum class CellState {
    Covered,
    Flagged,
    RevealedEmpty,
    RevealedNumber,
    RevealedMine,
    RevealedWrongFlag
};

class CellButton : public QPushButton {
    Q_OBJECT
public:
    explicit CellButton(int row, int col, QWidget* parent = nullptr);

    void setState(CellState state, int number = 0);

    int row() const { return m_row; }
    int col() const { return m_col; }

private:
    int m_row;
    int m_col;
    CellState m_state;
    int m_number;
};
#endif // CELLBUTTON_H
