#ifndef BOARDWIDGET_H
#define BOARDWIDGET_H

#include <QWidget>
#include <vector>
#include "CellButton.h"

class BoardWidget : public QWidget
{
    Q_OBJECT
public:
    BoardWidget(int rows, int cols, QWidget *parent = nullptr);

    void createGrid(int rows, int cols);
    CellButton* getCell(int row, int col);

signals:
    void cellLeftClicked(int row, int col);
    void cellRightClicked(int row, int col);

private slots:
    void handleLeftClick(int row, int col);
    void handleRightClick(int row, int col);

private:
    int rows;
    int cols;
    std::vector<std::vector<CellButton*>> buttons;
};

#endif // BOARDWIDGET_H
