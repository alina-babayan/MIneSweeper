#include "CellButton.h"

CellButton::CellButton(int row, int col, QWidget* parent)
    : QPushButton(parent), m_row(row), m_col(col), m_state(CellState::Covered), m_number(0)
{
    setFixedSize(30, 30);
    setFont(QFont("Segoe UI", 12, QFont::Bold));
    setState(CellState::Covered);
}

void CellButton::setState(CellState state, int number)
{
    m_state = state;
    m_number = number;

    setFlat(false);
    setText("");
    setStyleSheet("");

    switch (state) {
    case CellState::Covered:
        setStyleSheet("background-color: #C0C0C0; border: 2px outset #808080;");
        break;
    case CellState::Flagged:
        setText("🚩");
        setStyleSheet("background-color: #C0C0C0; border: 2px outset #808080;");
        break;
    case CellState::RevealedEmpty:
        setFlat(true);
        setStyleSheet("background-color: #E0E0E0;");
        break;
    case CellState::RevealedNumber:
        setFlat(true);
        switch (number) {
        case 1: setStyleSheet("background-color: #E0E0E0; color: #0000FF;"); break;
        case 2: setStyleSheet("background-color: #E0E0E0; color: #008000;"); break;
        case 3: setStyleSheet("background-color: #E0E0E0; color: #FF0000;"); break;
        case 4: setStyleSheet("background-color: #E0E0E0; color: #000080;"); break;
        case 5: setStyleSheet("background-color: #E0E0E0; color: #800000;"); break;
        case 6: setStyleSheet("background-color: #E0E0E0; color: #008080;"); break;
        case 7: setStyleSheet("background-color: #E0E0E0; color: #000000;"); break;
        case 8: setStyleSheet("background-color: #E0E0E0; color: #808080;"); break;
        }
        setText(QString::number(number));
        break;
    case CellState::RevealedMine:
        setFlat(true);
        setText("💣");
        setStyleSheet("background-color: #FF0000;");
        break;
    case CellState::RevealedWrongFlag:
        setFlat(true);
        setText("❌");
        setStyleSheet("background-color: #FFFF00;");
        break;
    }
}
