#ifndef TETRIMINO_H
#define TETRIMINO_H

#include "square.h"

class Tetrimino
{
public:
    Tetrimino(Grid grid);
    virtual void draw(Grid) = 0;
    void moveRight();
    void moveLeft();
    void rotate();


protected:
    void checkBottom();
    bool checkRightWall();
    bool checkLeftWall();
    Square square1, square2, square3, square4;
    bool stop{false};
};

class I_Block : public Tetrimino
{
public:
    I_Block(Grid);
    virtual void draw(Grid);
    bool fall();

private:
};

#endif
