#pragma once
#include "core/vec2.h"
#include "ecs/entity.h"
#include <unordered_map>

struct Transform {
    Vec2 position;
};

void transform_add(Entity e);
bool transform_has(Entity e);
Transform* transform_get(Entity e);
void transform_remove(Entity e);
