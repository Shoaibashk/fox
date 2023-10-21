#include <iostream>

#include "entt.hpp"
#include "Components.hpp"

#include "Entity.hpp"
#include "Scene.hpp"

using namespace Fox;

auto main(int argc, char *argv[]) -> int
{

  // auto active_scene = std::make_shared<entt::registry>();

  // auto active_scene = Fox::Scene().GetScene();
  Scene active_scene = Scene();

  // auto square = entt::entity();
  // auto square = active_scene->create();
  Entity square = active_scene.CreateEntity();
  square.AddComponent<Components::Position>(12, 34, 54);
  // active_scene->emplace<Components::Position>(square, 12, 34, 42);
  // square.AddComponent<Components::Position>(square, 12, 34, 42);

  // auto test = active_scene->get<Components::Position>(square);
  // auto active_scene = std::make_shared<fox::Scene>();

  // auto square = active_scene->CreateEntity;
  auto test = square.GetComponent<Components::Position>();

  std::cout << test.x << std::endl;
  std::cout << test.y << std::endl;
  std::cout << test.z << std::endl;

  return 0;
}
