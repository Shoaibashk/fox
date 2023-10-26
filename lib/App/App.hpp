#pragma once
#include <fox.hpp>
#include <fxpch.hpp>

#define SCREEN_W 1920
#define SCREEN_H 1080

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
