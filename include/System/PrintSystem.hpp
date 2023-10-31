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
            for (auto [entity, pos, scale, color] : Reg->view<Component::Position, Component::Scale, Color>().each())
            {
                DrawRectangleV({pos.x, pos.y}, {scale.x, scale.y}, color);
            }
        };
        void OnDetach() override
        {
        }
        PrintSystem(std::shared_ptr<fox::Scene> sceneHandle) : System(sceneHandle){};
        ~PrintSystem(){};
    };
} // namespace fox
