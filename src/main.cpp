#include "MainApp.hpp"

auto main() -> int
{
  fox::MainApp app;
  app.AddOverlay(new fox::EditorLayer("Editor"));
  app.Run();
  return 0;
}
