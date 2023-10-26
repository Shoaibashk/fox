

#include <fox.hpp>

namespace Systems
{

    class InputSystem : public fox::System
    {
    private:
        std::shared_ptr<entt::registry> Reg;
        std::shared_ptr<fox::Entity> Ent;

    public:
        void OnAttach() override
        {
            Reg = m_Scene->GetScene();
        };
        void OnUpdate() override
        {

            for (auto [entity, pos, scale] : Reg->view<Component::Position, Component::Scale>().each())
            {

                // Update-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
                if (IsKeyDown(KEY_RIGHT))
                    pos.x += 2.0f;
                if (IsKeyDown(KEY_LEFT))
                    pos.x -= 2.0f;
                if (IsKeyDown(KEY_UP))
                    pos.y -= 2.0f;
                if (IsKeyDown(KEY_DOWN))
                    pos.y += 2.0f;
                if (IsKeyDown(KEY_Z))
                    pos.z += 2.0f;
                if (IsKeyDown(KEY_X))
                    pos.z -= 2.0f;
            }
        };
        void OnDetach() override {}
        InputSystem(std::shared_ptr<fox::Scene> sceneHandle) : System(sceneHandle){};
        ~InputSystem(){};
    };
} // namespace fox
