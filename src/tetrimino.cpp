#include "tetrimino.h"

// TETRIMINO

Tetrimino::Tetrimino(Grid grid) : square1(grid), square2(grid, 5, 1), square3(grid, 5, -1), square4(grid, 5, -2) {}

void Tetrimino::rotate()
{
    square2.rotate(square1.getPos());
    square3.rotate(square1.getPos());
    square4.rotate(square1.getPos());

    if (checkLeftWall() || checkRightWall())
    {
        square2.reverse(square1.getPos());
        square3.reverse(square1.getPos());
        square4.reverse(square1.getPos());
    }
}

void Tetrimino::moveRight()
{
    if(checkRightWall()) { return; }

    square1.moveRight();
    square2.moveRight();
    square3.moveRight();
    square4.moveRight();
}

void Tetrimino::moveLeft() 
{
    if(checkLeftWall()) { return; }

    square1.moveLeft();
    square2.moveLeft();
    square3.moveLeft();
    square4.moveLeft();
}

void Tetrimino::checkBottom()
{
    if (square1.getPos().getGridY() == 19)
    {
        stop = true;
        return;
    }
    if (square2.getPos().getGridY() == 19)
    {
        stop = true;
        return;
    }
    if (square3.getPos().getGridY() == 19)
    {
        stop = true;
        return;
    }
    if (square4.getPos().getGridY() == 19)
    {
        stop = true;
        return;
    }
}

bool Tetrimino::checkRightWall()
{
    if (square1.getPos().getGridX() == 9)
    {
        return true;
    }
    if (square2.getPos().getGridX() == 9)
    {
        return true;
    }
    if (square3.getPos().getGridX() == 9)
    {
        return true;
    }
    if (square4.getPos().getGridX() == 9)
    {
        return true;
    }

    return false;
}

bool Tetrimino::checkLeftWall()
{
    if (square1.getPos().getGridX() == 0)
    {
        return true;
    }
    if (square2.getPos().getGridX() == 0)
    {
        return true;
    }
    if (square3.getPos().getGridX() == 0)
    {
        return true;
    }
    if (square4.getPos().getGridX() == 0)
    {
        return true;
    }

    return false;
}

// I_BLOCK

I_Block::I_Block(Grid grid) : Tetrimino(grid) {}

void I_Block::draw(Grid grid)
{
    square1.draw(grid);
    square2.draw(grid);
    square3.draw(grid);
    square4.draw(grid);
}

bool I_Block::fall()
{
    square1.fall();
    square2.fall();
    square3.fall();
    square4.fall();

    checkBottom();
    return stop;
}
