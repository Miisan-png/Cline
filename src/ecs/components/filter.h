#pragma once
#include "ecs/entity.h"

enum FilterMode { FILTER_NEAREST, FILTER_LINEAR };

void filter_add(Entity e, FilterMode mode);
void filter_remove(Entity e);
FilterMode filter_get(Entity e);
