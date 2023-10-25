#include <fxpch.hpp>
#include <Fox.hpp>

namespace Fox
{
    class EditorLayer : public Fox::Layer
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