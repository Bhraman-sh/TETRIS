#include "square.h"

Square::Square(Grid grid)
{
    this->length = grid.getLength();
}

Square::Square(Grid grid, int x, int y)
{
    this->length = grid.getLength();

    pos.setGridX(x);
    pos.setGridY(y);
}

void Square::fall()
{
    pos.fall();
}

void Square::moveRight()
{
    pos.moveRight();
}

void Square::moveLeft()
{
    pos.moveLeft();
}

void Square::draw(Grid grid)
{
    int actual_pos_x, actual_pos_y;
    actual_pos_x = grid.getGridPositionX()+ length * pos.getGridX();
    actual_pos_y = grid.getGridPositionY()+ length * pos.getGridY();
    DrawRectangle(actual_pos_x, actual_pos_y, length, length, BLUE);
}

void Square::rotate(Grid_Position pivot)
{
    int x_o, y_o, x, y, dx, dy;
    x_o = pivot.getGridX();
    y_o = pivot.getGridY();
    x = pos.getGridX();
    y = pos.getGridY();

    dx = x - x_o;
    dy = y - y_o;

    pos.setGridX(x_o - dy);
    pos.setGridY(y_o + dx);
}

void Square::reverse(Grid_Position pivot)
{
    int x_o, y_o, x, y, dx, dy;
    x_o = pivot.getGridX();
    y_o = pivot.getGridY();
    x = pos.getGridX();
    y = pos.getGridY();

    dx = x - x_o;
    dy = y - y_o;

    pos.setGridX(x_o + dy);
    pos.setGridY(y_o - dx);
}
