#pragma once
#include "ecs/entity.h"
#include "core/vec2.h"
#include <unordered_map>

struct Collider {
    Vec2 size;
    Vec2 offset;
    bool is_trigger;
};

void collider_add(Entity e);
bool collider_has(Entity e);
Collider* collider_get(Entity e);
void collider_remove(Entity e);
