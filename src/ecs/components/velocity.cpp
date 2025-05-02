#include "velocity.h"

static std::unordered_map<Entity, Velocity> velocities;

void velocity_add(Entity e) {
    velocities[e] = {};
}

bool velocity_has(Entity e) {
    return velocities.count(e);
}

Velocity* velocity_get(Entity e) {
    auto it = velocities.find(e);
    return it != velocities.end() ? &it->second : nullptr;
}

void velocity_remove(Entity e) {
    velocities.erase(e);
}
