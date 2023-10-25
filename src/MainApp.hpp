#include "App/App.hpp"
#include <Fox.hpp>
namespace Fox
{

    class MainApp : public App
    {
    private:
        std::shared_ptr<Scene> active_scene;
        std::shared_ptr<Entity> entities;
        LayerStack m_LayerStack;

        float m_LastFrameTime = 0.0f;

    public:
        void Setup()
        {

            for (auto layer : m_LayerStack)
            {
                layer->OnAttach();
            }

            // m_LayerStack.PushLayer(new EditorLayer("Editor"));

            entities = active_scene->CreateEntity();

            entities->AddComponent<Components::Position>((float)SCREEN_W / 2, (float)SCREEN_H / 2, (float)1);
            entities->AddComponent<Components::Scale>((float)1.0f, (float)1.0f, (float)1.0f);
            // entities.RemoveComponent<Components::Scale>();

            // m_PrintSystem(entities, active_scene);
        }
        void Update()
        { // Update
            for (auto layer : m_LayerStack)
            {
                layer->OnUpdate();
            }

            bool open = true;

            auto &ballPosition = entities->GetComponent<Components::Position>();

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
            active_scene->Update(GetFrameTime());
            // DrawText(std::to_string(valid).c_str(), 10, 120, 20, DARKGRAY);
        }
        void PushLayer(Layer *layer)
        {
            m_LayerStack.PushLayer(layer);
        }
        void PushOverlay(Layer *layer)
        {
            m_LayerStack.PushOverlay(layer);
        }
        MainApp()
        {
            active_scene = std::make_shared<Scene>();
        };
        ~MainApp() = default;
    };
}