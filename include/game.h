#ifndef GAME_H
#define GAME_H

#include "grid.h"
#include "tetrimino.h"

#include <iostream>
#include <random>

class Game
{
public:
    Game(int sw, int sh);
    void run();
private:

    void generateBlock();
    void handleInputs();
    void draw();
    Grid grid;

    std::mt19937 gen;
    // Game
    Tetrimino *block;
};

#endif
