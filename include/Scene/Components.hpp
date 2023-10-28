#pragma once
#include <fxpch.hpp>

namespace Component
{
    struct Position
    {
        float x;
        float y;
    };
    struct Rotation
    {
        float x;
        float y;
    };
    struct Scale
    {
        float x;
        float y;
    };

    struct Transform
    {
        Position position;
        Rotation rotation;
        Scale scale;
    };
} // namespace Components