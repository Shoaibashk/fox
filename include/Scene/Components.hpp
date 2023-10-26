#pragma once
#include <fxpch.hpp>

namespace Component
{
    struct Position
    {
        float x;
        float y;
        float z;
    };
    struct Rotation
    {
        float x;
        float y;
        float z;
    };
    struct Scale
    {
        float x;
        float y;
        float z;
    };

    struct Transform
    {
        Position position;
        Rotation rotation;
        Scale scale;
    };
} // namespace Components