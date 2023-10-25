#pragma once

#include "fxpch.hpp"
#include "Fox.hpp"

namespace Fox
{
    class Entity
    {

    private:
        entt::entity m_EntityHandle;
        std::shared_ptr<entt::registry> m_Scene;

    public:
        Entity(entt::entity handle, std::shared_ptr<entt::registry> scene) : m_EntityHandle(handle), m_Scene(scene)
        {
        }
        Entity()
        {
        }
        ~Entity()
        {
            std::cout << "All Entities are destroyed" << std::endl;
        }

        template <typename T, typename... Args>
        T &AddComponent(Args &&...args)
        {
            return m_Scene->emplace<T>(m_EntityHandle, std::forward<Args>(args)...);
        }

        template <typename T>
        T &GetComponent()
        {
            return m_Scene->get<T>(m_EntityHandle);
        }

        template <typename T>
        void RemoveComponent()
        {
            m_Scene->erase<T>(m_EntityHandle);
        }
    };

} // namespace Fox
