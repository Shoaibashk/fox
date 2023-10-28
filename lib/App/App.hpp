#pragma once
#include <fox.hpp>
#include <fxpch.hpp>

namespace fox
{

    class App
    {
    private:
    public:
        void Run();
        virtual void Setup() = 0;
        virtual void Update() = 0;
        App();
        ~App();
    };

} // namespace Fox
