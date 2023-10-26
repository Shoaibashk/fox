#pragma once
#include <fxpch.hpp>
#include <fox.hpp>

namespace fox
{
    class EditorLayer : public fox::Layer
    {
    private:
    public:
        void OnAttach() override
        {
            std::cout << "OnAttach Editor Layer" << std::endl;
        };
        void OnDetach() override
        {
            std::cout << "OnDetach Editor Layer" << std::endl;
        };
        void OnUpdate() override{
            // std::cout << "OnUpdate Editor Layer" << std::endl;
        };
        EditorLayer(std::string Name) : Layer(Name){};
        ~EditorLayer() override{};
    };

}