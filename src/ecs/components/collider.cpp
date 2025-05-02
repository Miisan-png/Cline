#include "collider.h"

static std::unordered_map<Entity, Collider> colliders;

void collider_add(Entity e) {
    colliders[e] = {Vec2(0.1f, 0.1f), Vec2(0, 0), false};
}

bool collider_has(Entity e) {
    return colliders.count(e);
}

Collider* collider_get(Entity e) {
    auto it = colliders.find(e);
    return it != colliders.end() ? &it->second : nullptr;
}

void collider_remove(Entity e) {
    colliders.erase(e);
}
