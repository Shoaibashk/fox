#pragma once

#include <fxpch.hpp>
#include <Fox.hpp>

namespace Fox
{
    class System
    {
    private:
    public:
        std::shared_ptr<Entity> m_Entity;
        std::shared_ptr<Scene> m_Scene;

        System(std::shared_ptr<Entity> entityHandle, std::shared_ptr<Scene> sceneHandle) : m_Entity(entityHandle), m_Scene(sceneHandle){};
        virtual ~System(){};
        virtual void OnAttach(){};
        virtual void OnDetach(){};
        virtual void OnUpdate(){};
    };
    class PrintSystem : public System
    {
    private:
    public:
        void OnAttach(){

        };
        void OnUpdate()
        {
            auto context = m_Scene->GetScene();

            for (auto [entity, pos, scale] : context->view<Components::Position, Components::Scale>().each())
            {
                std::cout << pos.x << std::endl;
                std::cout << pos.y << std::endl;
                std::cout << pos.z << std::endl;
                std::cout << scale.x << std::endl;
                std::cout << scale.y << std::endl;
                std::cout << scale.z << std::endl;
            }
        };
        void OnDetach() {}
        PrintSystem(std::shared_ptr<Entity> entityHandle, std::shared_ptr<Scene> sceneHandle) : System(entityHandle, sceneHandle){};
        ~PrintSystem(){};
    };

} // namespace Fox
