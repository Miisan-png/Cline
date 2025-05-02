#pragma once
#include "core/vec2.h"
#include "ecs/entity.h"
#include <unordered_map>

struct Velocity {
    Vec2 velocity;
};

void velocity_add(Entity e);
bool velocity_has(Entity e);
Velocity* velocity_get(Entity e);
void velocity_remove(Entity e);
