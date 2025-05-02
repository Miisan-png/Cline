#include "area.h"

static std::unordered_set<Entity> areas;

void area_add(Entity e) {
    areas.insert(e);
}

bool area_has(Entity e) {
    return areas.count(e);
}

void area_remove(Entity e) {
    areas.erase(e);
}
