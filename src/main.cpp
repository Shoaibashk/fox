#include <iostream>
#include <string>

#include "MainApp.hpp"

auto main() -> int
{
  Fox::MainApp app;
  app.PushOverlay(new Fox::EditorLayer("Editor"));
  app.Run();
  return 0;
}
