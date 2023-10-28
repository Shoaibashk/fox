#include "App.hpp"

void fox::App::Run()
{

    Setup();

    while (!WindowShouldClose())
    {
        BeginDrawing();
        rlImGuiBegin(); // starts the ImGui content mode. Make all ImGui calls after this
        ClearBackground(BLACK);
        Update();
        rlImGuiEnd(); // ends the ImGui content mode. Make all ImGui calls before this
        EndDrawing();
    }
}

fox::App::App()
{
    SetConfigFlags(FLAG_WINDOW_UNDECORATED | FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);
    InitWindow(SCREEN_W, SCREEN_H, "Test");

    SetTargetFPS(144);
    rlImGuiSetup(true);

    ImGui::GetIO().ConfigWindowsMoveFromTitleBarOnly = true;
}

fox::App::~App()
{
    rlImGuiShutdown(); // cleans up ImGui
    CloseWindow();
}
