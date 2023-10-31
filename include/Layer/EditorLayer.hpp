#pragma once
#include <fxpch.hpp>
#include <fox.hpp>
void ShowEditorDockSpace(bool *p_open);
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
            ShowEditorDockSpace((bool *)true);
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
                if ((uint32_t)entity == 0)
                {
                    ImGui::SliderFloat("PositionX", &pos.x, 0.0f, SCREEN_W, "%.3f", ImGuiSliderFlags());
                    ImGui::SliderFloat("PositionY", &pos.y, 0.0f, SCREEN_H, "%.3f", ImGuiSliderFlags());
                    ImGui::SliderFloat("ScaleX", &scl.x, 0.0f, 200.0f, "%.3f", ImGuiSliderFlags());
                    ImGui::SliderFloat("ScaleY", &scl.y, 0.0f, 200.0f, "%.3f", ImGuiSliderFlags());
                }
                // ImGui::SliderFloat("PositionZ", &pos.z, 0.0f, 200.0f, "%.3f", ImGuiSliderFlags());
                if ((uint32_t)entity == 1)
                {
                    ImGui::SliderFloat("1 PositionX", &pos.x, 0.0f, SCREEN_W, "%.3f", ImGuiSliderFlags());
                    ImGui::SliderFloat("1 PositionY", &pos.y, 0.0f, SCREEN_H, "%.3f", ImGuiSliderFlags());
                    ImGui::SliderFloat("1 ScaleX", &scl.x, 0.0f, 200.0f, "%.3f", ImGuiSliderFlags());
                    ImGui::SliderFloat("1 ScaleY", &scl.y, 0.0f, 200.0f, "%.3f", ImGuiSliderFlags());
                }
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

void ShowEditorDockSpace(bool *p_open)
{
    // READ THIS !!!
    // TL;DR; this demo is more complicated than what most users you would normally use.
    // If we remove all options we are showcasing, this demo would become:
    //     void ShowExampleAppDockSpace()
    //     {
    //         ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
    //     }
    // In most cases you should be able to just call DockSpaceOverViewport() and ignore all the code below!
    // In this specific demo, we are not using DockSpaceOverViewport() because:
    // - (1) we allow the host window to be floating/moveable instead of filling the viewport (when opt_fullscreen == false)
    // - (2) we allow the host window to have padding (when opt_padding == true)
    // - (3) we expose many flags and need a way to have them visible.
    // - (4) we have a local menu bar in the host window (vs. you could use BeginMainMenuBar() + DockSpaceOverViewport()
    //      in your code, but we don't here because we allow the window to be floating)

    static bool opt_fullscreen = true;
    static bool opt_padding = false;
    static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;
    dockspace_flags |= ImGuiDockNodeFlags_PassthruCentralNode;
    // ImGuiWindowFlags_NoBackground

    // We are using the ImGuiWindowFlags_NoDocking flag to make the parent window not dockable into,
    // because it would be confusing to have two docking targets within each others.
    ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
    if (opt_fullscreen)
    {
        const ImGuiViewport *viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(viewport->WorkPos);
        ImGui::SetNextWindowSize(viewport->WorkSize);
        ImGui::SetNextWindowViewport(viewport->ID);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
        window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBackground;
        window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
    }
    // else
    // {
    //     dockspace_flags &= ~ImGuiDockNodeFlags_PassthruCentralNode;
    // }

    // When using ImGuiDockNodeFlags_PassthruCentralNode, DockSpace() will render our background
    // and handle the pass-thru hole, so we ask Begin() to not render a background.
    // if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
    //     window_flags |= ImGuiWindowFlags_NoBackground;

    // Important: note that we proceed even if Begin() returns false (aka window is collapsed).
    // This is because we want to keep our DockSpace() active. If a DockSpace() is inactive,
    // all active windows docked into it will lose their parent and become undocked.
    // We cannot preserve the docking relationship between an active window and an inactive docking, otherwise
    // any change of dockspace/settings would lead to windows being stuck in limbo and never being visible.
    if (!opt_padding)
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
    ImGui::Begin("DockSpace Demo", p_open, window_flags);
    // if (!opt_padding)
    ImGui::PopStyleVar();

    // if (opt_fullscreen)
    ImGui::PopStyleVar(2);

    // Submit the DockSpace
    ImGuiIO &io = ImGui::GetIO();

    if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
    {
        ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
        ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
    }
    else
    {

        // ImGuiIO &io = ImGui::GetIO();
        // ImGui::Text("ERROR: Docking is not enabled! See Demo > Configuration.");
        // ImGui::Text("Set io.ConfigFlags |= ImGuiConfigFlags_DockingEnable in your code, or ");
        // ImGui::SameLine(0.0f, 0.0f);
        // if (ImGui::SmallButton("click here"))
        //     io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    }

    if (ImGui::BeginMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {
            // Disabling fullscreen would allow the window to be moved to the front of other windows,
            // which we can't undo at the moment without finer window depth/z control.
            // ImGui::MenuItem("Fullscreen", NULL, &opt_fullscreen);
            // ImGui::MenuItem("Padding", NULL, &opt_padding);
            // ImGui::Separator();

            if (ImGui::MenuItem("Flag: NoDockingOverCentralNode", "", (dockspace_flags & ImGuiDockNodeFlags_NoDockingOverCentralNode) != 0))
            {
                dockspace_flags ^= ImGuiDockNodeFlags_NoDockingOverCentralNode;
            }
            if (ImGui::MenuItem("Flag: NoDockingSplit", "", (dockspace_flags & ImGuiDockNodeFlags_NoDockingSplit) != 0))
            {
                dockspace_flags ^= ImGuiDockNodeFlags_NoDockingSplit;
            }
            if (ImGui::MenuItem("Flag: NoUndocking", "", (dockspace_flags & ImGuiDockNodeFlags_NoUndocking) != 0))
            {
                dockspace_flags ^= ImGuiDockNodeFlags_NoUndocking;
            }
            if (ImGui::MenuItem("Flag: NoResize", "", (dockspace_flags & ImGuiDockNodeFlags_NoResize) != 0))
            {
                dockspace_flags ^= ImGuiDockNodeFlags_NoResize;
            }
            if (ImGui::MenuItem("Flag: AutoHideTabBar", "", (dockspace_flags & ImGuiDockNodeFlags_AutoHideTabBar) != 0))
            {
                dockspace_flags ^= ImGuiDockNodeFlags_AutoHideTabBar;
            }
            // if (ImGui::MenuItem("Flag: PassthruCentralNode", "", (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode) != 0, opt_fullscreen))
            // {
            //     dockspace_flags ^= ImGuiDockNodeFlags_PassthruCentralNode;
            // }
            ImGui::Separator();

            if (ImGui::MenuItem("Close", NULL, false, p_open != NULL))
                *p_open = false;
            ImGui::EndMenu();
        }
        // HelpMarker(
        //     "When docking is enabled, you can ALWAYS dock MOST window into another! Try it now!"
        //     "\n"
        //     "- Drag from window title bar or their tab to dock/undock."
        //     "\n"
        //     "- Drag from window menu button (upper-left button) to undock an entire node (all windows)."
        //     "\n"
        //     "- Hold SHIFT to disable docking (if io.ConfigDockingWithShift == false, default)"
        //     "\n"
        //     "- Hold SHIFT to enable docking (if io.ConfigDockingWithShift == true)"
        //     "\n"
        //     "This demo app has nothing to do with enabling docking!"
        //     "\n\n"
        //     "This demo app only demonstrate the use of ImGui::DockSpace() which allows you to manually create a docking node _within_ another window."
        //     "\n\n"
        //     "Read comments in ShowExampleAppDockSpace() for more details.");

        ImGui::EndMenuBar();
    }

    ImGui::End();
}
