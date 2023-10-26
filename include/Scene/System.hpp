#pragma once

#include <fxpch.hpp>
#include <fox.hpp>

namespace fox
{
    class System
    {
    private:
    public:
        std::shared_ptr<Scene> m_Scene;

        System(std::shared_ptr<Scene> sceneHandle) : m_Scene(sceneHandle){};
        virtual ~System(){};
        virtual void OnAttach(){};
        virtual void OnDetach(){};
        virtual void OnUpdate(){};
    };

} // namespace Fox
