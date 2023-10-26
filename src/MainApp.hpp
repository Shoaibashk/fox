#pragma once

#include <fxpch.hpp>
#include <fox.hpp>
#include "App/App.hpp"

namespace fox
{

    class MainApp : public App
    {
    private:
        std::shared_ptr<Scene> active_scene;
        std::shared_ptr<Entity> entities;
        LayerStack m_LayerStack;
        SystemStack m_SystemStack;
        float m_LastFrameTime = 0.0f;

    public:
        void Setup()
        {

            entities = active_scene->CreateEntity();

            for (auto layer : m_LayerStack)
            {
                layer->OnAttach();
            }

            entities->AddComponent<Component::Position>((float)SCREEN_W / 2, (float)SCREEN_H / 2, (float)1);
            entities->AddComponent<Component::Scale>((float)1.0f, (float)1.0f, (float)1.0f);

            AddSystem(new Systems::InputSystem(active_scene));
            AddSystem(new Systems::PrintSystem(active_scene));

            for (auto system : m_SystemStack)
            {
                system->OnAttach();
            }

            // m_PrintSystem(entities, active_scene);
        }
        void Update()
        { // Update
            for (auto layer : m_LayerStack)
            {
                layer->OnUpdate();
            }

            // show ImGui Content
            bool open = true;
            if (ImGui::BeginMainMenuBar())
            {
                if (ImGui::BeginMenu("File"))
                {
                    // if (ImGui::MenuItem("Exit"))
                    //     open = true;

                    ImGui::EndMenu();
                }

                if (ImGui::BeginMenu("Window"))
                {
                    ImGui::MenuItem("ImGui Demo", nullptr, &open);
                    ImGui::MenuItem("Image Viewer", nullptr, &open);
                    ImGui::MenuItem("3D View", nullptr, &open);

                    ImGui::EndMenu();
                }
                ImGui::EndMainMenuBar();
            }

            for (auto system : m_SystemStack)
            {
                system->OnUpdate();
            }
            // DrawText(std::to_string(valid).c_str(), 10, 120, 20, DARKGRAY);
        }
        void AddLayer(Layer *layer)
        {
            m_LayerStack.PushLayer(layer);
        }
        void AddOverlay(Layer *layer)
        {
            m_LayerStack.PushOverlay(layer);
        }
        void AddSystem(System *system)
        {
            m_SystemStack.PushSystem(system);
        }
        MainApp()
        {
            active_scene = std::make_shared<Scene>();
        };
        ~MainApp() = default;
    };
}