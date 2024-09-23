#ifndef TETRIMINO_H
#define TETRIMINO_H

#include "square.h"

class Tetrimino
{
public:
    Tetrimino(Grid grid, int, int, int, int, int ,int);
    virtual void draw(Grid);
    void moveRight();
    void moveLeft();
    virtual void rotate();
    bool fall();


protected:
    void drawStaticBoxes(Grid);
    void markGrid();
    void checkBottom();
    bool checkRightWall();
    bool checkLeftWall();
    Square square1, square2, square3, square4;
    bool stop{false};

private:

    void refresh(int);

    static bool boxes[20][10];
    static int flag[20];
};

class I_Block : public Tetrimino
{
public:
   I_Block(Grid grid ,int a = 1, int b = -1, int c = -2, int d = 5, int e = 5, int f = 5);

private:
};

class Square_Block : public Tetrimino
{
public:
    Square_Block(Grid grid,int a = 0, int b = -1, int c = -1, int d = 4, int e = 5, int f = 4);
    void rotate() {}

private:
};
#endif
