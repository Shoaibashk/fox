#pragma once
#define SCREEN_W 1920
#define SCREEN_H 1080
#include "raylib.h"

#include "raymath.h"

#include "imgui_impl_raylib.h"
#include "rlImGui.h"
#include "entt.hpp"

#include "Scene/Components.hpp"
#include "Scene/Entity.hpp"
#include "Scene/Scene.hpp"
#include "Scene/System.hpp"
#include "Core/LayerStack.hpp"
#include "Core/Layer.hpp"
#include "Core/SystemStack.hpp"

#include "Layer/EditorLayer.hpp"
#include "System/InputSystem.hpp"
#include "System/PrintSystem.hpp"
