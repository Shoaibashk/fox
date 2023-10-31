

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

                if ((uint32_t)entity == 0)
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
                    // if (IsKeyDown(KEY_D))
                    //     scale.x += 2.0f;
                    // if (IsKeyDown(KEY_A))
                    //     scale.x -= 2.0f;
                    // if (IsKeyDown(KEY_S))
                    //     scale.y += 2.0f;
                    // if (IsKeyDown(KEY_W))
                    //     scale.y -= 2.0f;
                }
                if ((uint32_t)entity == 1)
                {
                    // Update-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
                    if (IsKeyDown(KEY_D))
                        pos.x += 2.0f;
                    if (IsKeyDown(KEY_A))
                        pos.x -= 2.0f;
                    if (IsKeyDown(KEY_W))
                        pos.y -= 2.0f;
                    if (IsKeyDown(KEY_S))
                        pos.y += 2.0f;
                    // if (IsKeyDown(KEY_D))
                    //     scale.x += 2.0f;
                    // if (IsKeyDown(KEY_A))
                    //     scale.x -= 2.0f;
                    // if (IsKeyDown(KEY_S))
                    //     scale.y += 2.0f;
                    // if (IsKeyDown(KEY_W))
                    //     scale.y -= 2.0f;
                }
            }
        };
        void OnDetach() override {}
        InputSystem(std::shared_ptr<fox::Scene> sceneHandle) : System(sceneHandle){};
        ~InputSystem(){};
    };
} // namespace fox
