#ifndef SQUARE_H
#define SQUARE_H

#include "grid.h"

class Square
{
public:
    Square(Grid);
    Square(Grid, int, int);
    void fall();
    void moveRight();
    void moveLeft();
    void draw(Grid);
    void rotate(Grid_Position pivot);
    void reverse(Grid_Position pivot);
    Grid_Position getPos() { return pos; };
private:
    Grid_Position pos;
    int length;
};


#endif
