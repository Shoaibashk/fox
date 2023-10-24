#include <App.hpp>
namespace Fox
{

    class MainApp : public App
    {
    private:
        Scene active_scene;
        Entity entities;

    public:
        virtual void Setup()
        {
            auto active_scene = std::make_shared<Scene>();

            entities = active_scene->CreateEntity();
            entities.AddComponent<Components::Position>((float)SCREEN_W / 2, (float)SCREEN_H / 2, (float)1);
            entities.AddComponent<Components::Scale>((float)1.0f, (float)1.0f, (float)1.0f);
            entities.RemoveComponent<Components::Scale>();
        }
        virtual void Update()
        { // Update

            auto &ballPosition = entities.GetComponent<Components::Position>();

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

            GuiSliderBar({ballPosition.x - 50, ballPosition.y + 120, 100, 20}, "+", "-", &ballPosition.z, 1, 100);

            DrawCircle(ballPosition.x, ballPosition.y, ballPosition.z, RED);

            DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);
            DrawText(std::to_string(ballPosition.x).c_str(), 10, 30, 20, DARKGRAY);
            DrawText(std::to_string(ballPosition.y).c_str(), 10, 60, 20, DARKGRAY);
            DrawText(std::to_string(ballPosition.z).c_str(), 10, 90, 20, DARKGRAY);
            // DrawText(std::to_string(valid).c_str(), 10, 120, 20, DARKGRAY);
        }

        MainApp() = default;
        ~MainApp() = default;
    };
}