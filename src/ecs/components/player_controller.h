#pragma once
#include "ecs/entity.h"
#include <unordered_set>

void player_controller_add(Entity e);
bool player_controller_has(Entity e);
void player_controller_remove(Entity e);
