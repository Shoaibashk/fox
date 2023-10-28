#pragma once
#include <fxpch.hpp>
#include <fox.hpp>

namespace fox
{
    class EditorLayer : public fox::Layer
    {
    private:
        std::shared_ptr<fox::Scene> scene;
        bool is_tool_active = false;
        float my_color = 2.0f;
        bool CopyFlag = false;
        bool PasteFlag = false;
        bool viewFlag = false;

    public:
        void OnAttach(std::shared_ptr<fox::Scene> scene) override
        {
            this->scene = scene;
            // std::cout << "OnAttach Editor Layer" << std::endl;
            // setup Dear Imoui context
        };
        void OnDetach() override
        {

            std::cout << "OnDetach Editor Layer" << std::endl;
        };
        void OnUpdate() override
        {

            auto Reg = scene->GetScene();

            // Create a window called "My First Tool", with a menu bar.
            ImGui::Begin("Components", &is_tool_active, ImGuiWindowFlags_MenuBar);
            // if (ImGui::BeginMenuBar())
            // {
            //     if (ImGui::BeginMenu("File"))
            //     {
            //         if (ImGui::MenuItem("Open..", "Ctrl+O"))
            //         { /* Do stuff */
            //         }
            //         if (ImGui::MenuItem("Save", "Ctrl+S"))
            //         { /* Do stuff */
            //         }
            //         if (ImGui::MenuItem("Close", "Ctrl+W"))
            //         {
            //             is_tool_active = false;
            //         }
            //         ImGui::EndMenu();
            //     }
            //     ImGui::EndMenuBar();
            // }
            for (auto [entity, pos, scl] : Reg->view<Component::Position, Component::Scale>().each())
            {
                // Edit a color stored as 4 floats
                // ImGui::ColorEdit4("Color", &my_color);
                ImGui::SliderFloat("PositionX", &pos.x, 0.0f, SCREEN_W, "%.3f", ImGuiSliderFlags());
                ImGui::SliderFloat("PositionY", &pos.y, 0.0f, SCREEN_H, "%.3f", ImGuiSliderFlags());
                // ImGui::SliderFloat("PositionZ", &pos.z, 0.0f, 200.0f, "%.3f", ImGuiSliderFlags());
                ImGui::SliderFloat("ScaleX", &scl.x, 0.0f, 200.0f, "%.3f", ImGuiSliderFlags());
                ImGui::SliderFloat("ScaleY", &scl.y, 0.0f, 200.0f, "%.3f", ImGuiSliderFlags());
                // ImGui::SliderFloat("ScaleZ", &scl.z, 0.0f, 200.0f, "%.3f", ImGuiSliderFlags());
            }
            // // Generate samples and plot them
            // float samples[100];
            // for (int n = 0; n < 100; n++)
            //     samples[n] = sinf(n * 1.0f + ImGui::GetTime() * 1.5f);
            // ImGui::PlotLines("Samples", samples, 100);

            // // Display contents in a scrolling region
            // ImGui::TextColored(ImVec4(1, 1, 0, 1), "Important Stuff");
            // ImGui::BeginChild("Scrolling");
            // for (int n = 0; n < 50; n++)
            //     ImGui::Text("%04d: Some text", n);
            // ImGui::EndChild();
            ImGui::End();

            // std::cout << "OnUpdate Editor Layer" << std::endl;
        };

        EditorLayer(std::string Name) : Layer(Name){};
        ~EditorLayer() override{};
    };
}