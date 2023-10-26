#pragma once
#include <fox.hpp>

namespace Systems
{

    class PrintSystem : public fox::System
    {
    private:
        std::shared_ptr<entt::registry> Reg;

    public:
        void OnAttach() override
        {
            Reg = m_Scene->GetScene();
        };
        void OnUpdate() override
        {

            for (auto [entity, pos, scale] : Reg->view<Component::Position, Component::Scale>().each())
            {

                GuiSliderBar({pos.x - 50, pos.y + 120, 100, 20}, "+", "-", &pos.z, 1, 100);

                DrawCircle(pos.x, pos.y, pos.z, GREEN);

                DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);
                DrawText(std::to_string(pos.x).c_str(), 10, 30, 20, DARKGRAY);
                DrawText(std::to_string(pos.y).c_str(), 10, 60, 20, DARKGRAY);
                DrawText(std::to_string(pos.z).c_str(), 10, 90, 20, DARKGRAY);
                // std::cout << pos.x << std::endl;
                // std::cout << pos.y << std::endl;
                // std::cout << pos.z << std::endl;
                // std::cout << "-------------------------------------------" << std::endl;
                // std::cout << scale.x << std::endl;
                // std::cout << scale.y << std::endl;
                // std::cout << scale.z << std::endl;
                // std::cout << "-------------------------------------------" << std::endl;
            }
        };
        void OnDetach() override
        {
        }
        PrintSystem(std::shared_ptr<fox::Scene> sceneHandle) : System(sceneHandle){};
        ~PrintSystem(){};
    };
} // namespace fox
