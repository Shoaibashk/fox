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

    public:
        void Setup()
        {

            // ImGui::StyleColorsDark();

            // ImGuiStyle &style = ImGui::GetStyle();
            // if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
            // {
            //     style.WindowRounding = 0.0f;
            //     style.Colors[ImGuiCol_WindowBg].w = 1.0f;
            // }
            active_scene = std::make_shared<Scene>();
            entities = active_scene->CreateEntity();

            entities->AddComponent<Component::Position>((float)SCREEN_W / 2, (float)SCREEN_H / 2);
            entities->AddComponent<Component::Scale>((float)20.0f, (float)20.0f);

            AddSystem(new Systems::InputSystem(active_scene));
            AddSystem(new Systems::PrintSystem(active_scene));

            for (auto layer : m_LayerStack)
            {
                layer->OnAttach(active_scene);
            }
            for (auto system : m_SystemStack)
            {
                system->OnAttach();
            }
        }
        void Update()
        { // Update

            for (auto layer : m_LayerStack)
            {
                layer->OnUpdate();
            }

            for (auto system : m_SystemStack)
            {
                system->OnUpdate();
            }

            // if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
            // {
            //     ImGui::UpdatePlatformWindows();
            //     ImGui::RenderPlatformWindowsDefault();
            // }
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