#include "player_controller.h"

static std::unordered_set<Entity> player_controllers;

void player_controller_add(Entity e) {
    player_controllers.insert(e);
}

bool player_controller_has(Entity e) {
    return player_controllers.count(e);
}

void player_controller_remove(Entity e) {
    player_controllers.erase(e);
}
