
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

namespace Fox
{

    class App
    {
    private:
    public:
        void Run();
        virtual void Setup() = 0;
        virtual void Update() = 0;
        App();
        ~App();
    };

} // namespace Fox
