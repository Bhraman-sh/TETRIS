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

class Z_Block : public Tetrimino
{
public:
    Z_Block(Grid grid, int a = -1, int b = -1, int c = 0, int d = 5, int e = 4, int f = 6);

private:
};

class S_Block : public Tetrimino
{
public:
    S_Block(Grid grid, int a = -1, int b = -1, int c = 0, int d = 5, int e = 6, int f = 4);

private:
};

class L_Block : public Tetrimino
{
public:
    L_Block(Grid grid, int a = -1, int b = 1, int c = 1, int d = 5, int e = 5, int f = 6);

private:
};

class J_Block : public Tetrimino
{
public:
    J_Block(Grid grid, int a = -1, int b = 1, int c = 1, int d = 5, int e = 5, int f = 4);

private:
};

class T_Block : public Tetrimino
{
public:
    T_Block(Grid grid, int a = -1, int b = 0, int c = 0, int d = 5, int e = 6, int f = 4);

private:
};

#endif
