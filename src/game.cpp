#include "game.h"

Game::Game(int screenWidth, int screenHeight) : grid(screenWidth, screenHeight), gen(std::random_device{}())
{
    InitWindow(screenWidth, screenHeight, "Tetris");
    generateBlock();
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
        if (time2 - time1 >= 0.2)
        {
            time1 = time2;
            if(block->fall())
            {
                delete block;
                generateBlock();
            }
        }
 
    }
}

void Game::generateBlock()
{
    std::uniform_int_distribution<> dis(1, 7);
    int a = dis(gen);

    std::cout << a << std::endl;

    switch (a)
    {
        case (1):
            block = new I_Block(grid);
            std::cout << "i block" << std::endl;
            break;

        case (2):
            block = new Square_Block(grid);
            std::cout << "square block" << std::endl;
            break;

        case (3):
            block = new Z_Block(grid);
            std::cout << "Z block" << std::endl;
            break;

        case (4):
            block = new S_Block(grid);
            std::cout << "S block" << std::endl;
            break;

        case (5):
            block = new L_Block(grid);
            std::cout << "Z block" << std::endl;
            break;

        case (6):
            block = new L_Block(grid);
            std::cout << "L block" << std::endl;
            break;

        case (7):
            block = new T_Block(grid);
            std::cout << "T block" << std::endl;
            break;

        default:
            break;
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
