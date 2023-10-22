#include <iostream>
#include <string>

#include "entt.hpp"
#include "Components.hpp"

#include "Entity.hpp"
#include "Scene.hpp"
#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#define SCREEN_W 1920
#define SCREEN_H 1080

using namespace Fox;

auto main(int argc, char *argv[]) -> int
{
  InitWindow(SCREEN_W, SCREEN_H, "Test");
  SetTargetFPS(60);

  // auto active_scene = std::make_shared<entt::registry>();

  // auto active_scene = Fox::Scene().GetScene();
  Scene active_scene = Scene();

  // auto square = entt::entity();
  // auto square = active_scene->create();
  Entity square = active_scene.CreateEntity();
  square.AddComponent<Components::Position>((float)SCREEN_W / 2, (float)SCREEN_H / 2, (float)1);
  square.AddComponent<Components::Scale>((float)1.0f, (float)1.0f, (float)1.0f);
  // active_scene->emplace<Components::Position>(square, 12, 34, 42);
  // square.AddComponent<Components::Position>(square, 12, 34, 42);

  // auto test = active_scene->get<Components::Position>(square);
  // auto active_scene = std::make_shared<fox::Scene>();

  // auto square = active_scene->CreateEntity;
  GuiTextBox(Rectangle{10, 120, 80, 50}, "", 20, true);
  while (!WindowShouldClose())
  {

    // Update
    auto &ballPosition = square.GetComponent<Components::Position>();

    // Update
    //----------------------------------------------------------------------------------
    if (IsKeyDown(KEY_RIGHT))
      ballPosition.x += 2.0f;
    if (IsKeyDown(KEY_LEFT))
      ballPosition.x -= 2.0f;
    if (IsKeyDown(KEY_UP))
      ballPosition.y -= 2.0f;
    if (IsKeyDown(KEY_DOWN))
      ballPosition.y += 2.0f;
    if (IsKeyDown(KEY_Z))
      ballPosition.z += 2.0f;
    if (IsKeyDown(KEY_X))
      ballPosition.z -= 2.0f;
    //----------------------------------------------------------------------------------

    // Draw
    BeginDrawing();

    ClearBackground(BLACK);

    GuiSliderBar({ballPosition.x - 50, ballPosition.y + 120, 100, 20}, "+", "-", &ballPosition.z, 1, 100);


    DrawCircle(ballPosition.x, ballPosition.y, ballPosition.z, RED);

    DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);
    DrawText(std::to_string(ballPosition.x).c_str(), 10, 30, 20, DARKGRAY);
    DrawText(std::to_string(ballPosition.y).c_str(), 10, 60, 20, DARKGRAY);
    DrawText(std::to_string(ballPosition.z).c_str(), 10, 90, 20, DARKGRAY);

    EndDrawing();
  }
  CloseWindow();
  return 0;
}
