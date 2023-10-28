#pragma once

#include "fox.hpp"

namespace fox
{

    class Layer
    {

    public:
        Layer(const std::string &name = "Layer") : m_DebugName(name){};
        virtual ~Layer() {}
        virtual void OnAttach(std::shared_ptr<Scene> scene)
        {
            this->m_Scene = scene;
        }
        virtual void OnDetach() {}
        virtual void OnUpdate() {}
        // virtual void OnEvent(Event& event) {}
        inline const std::string &GetName() const
        {
            return m_DebugName;
        };

    private:
        std::shared_ptr<Scene> m_Scene;
        std::string m_DebugName;
    };

}