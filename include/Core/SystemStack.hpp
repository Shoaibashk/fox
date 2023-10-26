#pragma once

#include <fox.hpp>
#include <fxpch.hpp>

namespace fox
{
    class SystemStack
    {
    public:
        SystemStack() = default;
        ~SystemStack()
        {
            for (System *System : m_System)
            {
                System->OnDetach();
                delete System;
            }
        };

        void PushSystem(System *System)
        {
            m_System.emplace(m_System.begin() + m_SystemInsertIndex, System);
            m_SystemInsertIndex++;
        }

        void PushOverlay(System *overlay)
        {
            m_System.emplace_back(overlay);
        }
        void PopSystem(System *System)
        {
            auto it = std::find(m_System.begin(), m_System.begin() + m_SystemInsertIndex, System);
            if (it != m_System.begin() + m_SystemInsertIndex)
            {
                System->OnDetach();
                m_System.erase(it);
                m_SystemInsertIndex--;
            }
        }

        void PopOverlay(System *overlay)
        {
            auto it = std::find(m_System.begin() + m_SystemInsertIndex, m_System.end(), overlay);
            if (it != m_System.end())
            {
                overlay->OnDetach();
                m_System.erase(it);
            }
        }

        std::vector<System *>::iterator begin() { return m_System.begin(); }
        std::vector<System *>::iterator end() { return m_System.end(); }
        std::vector<System *>::reverse_iterator rbegin() { return m_System.rbegin(); }
        std::vector<System *>::reverse_iterator rend() { return m_System.rend(); }

        std::vector<System *>::const_iterator begin() const { return m_System.begin(); }
        std::vector<System *>::const_iterator end() const { return m_System.end(); }
        std::vector<System *>::const_reverse_iterator rbegin() const { return m_System.rbegin(); }
        std::vector<System *>::const_reverse_iterator rend() const { return m_System.rend(); }

    private:
        std::vector<System *> m_System;
        unsigned int m_SystemInsertIndex = 0;
    };
} // namespace fox
