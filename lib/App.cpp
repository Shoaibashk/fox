#include "App.hpp"

void Fox::App::Run()
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

Fox::App::App()
{
    InitWindow(SCREEN_W, SCREEN_H, "Test");
    SetTargetFPS(60);
}

Fox::App::~App()
{
    std::cout << "Application Closed" << std::endl;
    CloseWindow();
}
