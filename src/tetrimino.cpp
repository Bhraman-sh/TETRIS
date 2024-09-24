#include "tetrimino.h"

// TETRIMINO

Tetrimino::Tetrimino(Grid grid, int a, int b, int c, int d, int e, int f) : square1(grid), square2(grid, d, a), square3(grid, e, b), square4(grid, f, c) 
{
}

void Tetrimino::drawStaticBoxes(Grid grid)
{
    int x = grid.getGridPositionX();
    int y = grid.getGridPositionY();
    int l = grid.getLength();

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (boxes[j][i])
            {
                DrawRectangle(x + i * l, y + j * l, l, l, BLUE);
            }
        }
    }
}

void Tetrimino::markGrid()
{
    int s1 = square1.getPos().getGridY();
    int s2 = square2.getPos().getGridY();
    int s3 = square3.getPos().getGridY();
    int s4 = square4.getPos().getGridY();
    boxes[s1][square1.getPos().getGridX()] = true;
    boxes[s2][square2.getPos().getGridX()] = true;
    boxes[s3][square3.getPos().getGridX()] = true;
    boxes[s4][square4.getPos().getGridX()] = true;

    flag[s1]++;
    flag[s2]++;
    flag[s3]++;
    flag[s4]++;

    s1 = (s1 > s2 ? s1 : s2);
    s3 = (s3 > s4 ? s3 : s4);
    s1 = (s1 > s3 ? s1 : s3);

    if (flag[s1] == 10) { refresh(s1); }
}

void Tetrimino::refresh(int s)
{
    int i = s;
    while (i != 0)
    {
        for (int j = 0; j < 10; j++)
        {
            boxes[i][j] = boxes[i-1][j];
        }
        flag[i] = flag[i-1];
        i--;
    }
    flag[0] = 0;
    for (i = 0; i < 10; i++)
    {
        boxes[0][i] = false;
    }

    if (flag[s] == 10) { refresh(s); }
}

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
    if ((square1.getPos().getGridY() == 19) || boxes[square1.getPos().getGridY() + 1][square1.getPos().getGridX()])
    {
        markGrid();
        stop = true;
        return;
    }
    if ((square2.getPos().getGridY() == 19) || boxes[square2.getPos().getGridY() + 1][square2.getPos().getGridX()])
    {
        markGrid();
        stop = true;
        return;
    }
    if ((square3.getPos().getGridY() == 19) || boxes[square3.getPos().getGridY() + 1][square3.getPos().getGridX()])
    {
        markGrid();
        stop = true;
        return;
    }
    if ((square4.getPos().getGridY() == 19) || boxes[square4.getPos().getGridY() + 1][square4.getPos().getGridX()])
    {
        markGrid();
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

void Tetrimino::draw(Grid grid)
{
    drawStaticBoxes(grid);

    square1.draw(grid);
    square2.draw(grid);
    square3.draw(grid);
    square4.draw(grid);
}

bool Tetrimino::fall()
{
    square1.fall();
    square2.fall();
    square3.fall();
    square4.fall();

    checkBottom();
    return stop;
}

bool Tetrimino::boxes[20][10] = {false};
int Tetrimino::flag[20] = {0};

// I_BLOCK

I_Block::I_Block(Grid grid ,int a, int b, int c, int d, int e, int f) : Tetrimino(grid, a, b, c, d, e, f) {}

Square_Block::Square_Block(Grid grid, int a, int b, int c, int d, int e, int f): Tetrimino(grid, a, b, c, d, e, f) {}

Z_Block::Z_Block(Grid grid, int a, int b, int c, int d, int e, int f): Tetrimino(grid, a, b, c, d, e, f) {}
