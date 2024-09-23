#ifndef GAME_H
#define GAME_H

#include "grid.h"
#include "tetrimino.h"

class Game
{
public:
    Game(int sw, int sh);
    void run();
private:
    void handleInputs();
    void draw();
    Grid grid;

    // Game
    Tetrimino *block;
};

#endif
