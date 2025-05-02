#include "transform.h"

static std::unordered_map<Entity, Transform> transforms;

void transform_add(Entity e) {
    transforms[e] = {};
}

bool transform_has(Entity e) {
    return transforms.count(e);
}

Transform* transform_get(Entity e) {
    auto it = transforms.find(e);
    return it != transforms.end() ? &it->second : nullptr;
}

void transform_remove(Entity e) {
    transforms.erase(e);
}
