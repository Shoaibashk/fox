#include "App.hpp"

void fox::App::Run()
{

    Setup();

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);
        Update();

        EndDrawing();
    }
}

fox::App::App()
{
    InitWindow(SCREEN_W, SCREEN_H, "Test");
    SetTargetFPS(144);
}

fox::App::~App()
{
    std::cout << "Application Closed" << std::endl;
    CloseWindow();
}
