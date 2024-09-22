#include "game.h"

Game::Game(int screenWidth, int screenHeight) : grid(screenWidth, screenHeight)
{
    InitWindow(screenWidth, screenHeight, "Tetris");
    block = new I_Block(grid);
}

void Game::run()
{
    double time1 = GetTime();
    double time2;

    while(!WindowShouldClose())
    {
        draw();
        handleInputs();

        double time2 = GetTime();
        if (time2 - time1 >= 0.5)
        {
            time1 = time2;
            if(block->fall())
            {
                delete block;
                block = new I_Block(grid);
            }
        }
 
    }
}

void Game::handleInputs()
{
    if (IsKeyPressed(KEY_UP))
    {
        block->rotate();
    }

    if (IsKeyPressed(KEY_RIGHT))
    {
        block->moveRight();
    }

    if (IsKeyPressed(KEY_LEFT))
    {
        block->moveLeft();
    }
}

void Game::draw()
{
    ClearBackground(BLACK);
    BeginDrawing();

    grid.drawGrid();
    block->draw(grid);
    EndDrawing();
}
