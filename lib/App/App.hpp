#pragma once
#include <fox.hpp>
#include <fxpch.hpp>

#define SCREEN_W 1280
#define SCREEN_H 768

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
