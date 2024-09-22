#include <iostream>

#include "game.h"

int main()
{
    std::cout << "TETRIS" << std::endl;
    Game game(800, 600);

    game.run();

    return 0;
}


