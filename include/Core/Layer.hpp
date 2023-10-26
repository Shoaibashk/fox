#pragma once

#include "fox.hpp"

namespace fox
{

    class Layer
    {

    public:
        Layer(const std::string &name = "Layer") : m_DebugName(name){};
        virtual ~Layer() {}
        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate() {}
        // virtual void OnEvent(Event& event) {}
        inline const std::string &GetName() const
        {
            return m_DebugName;
        };

    private:
        std::string m_DebugName;
    };

}