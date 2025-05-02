#include "ecs/components/transform.h"

void system_world_bounds() {
    for (Entity e = 1; e < 10000; ++e) {
        if (transform_has(e)) {
            auto* t = transform_get(e);
            if (t->position.x < -1.0f) t->position.x = -1.0f;
            if (t->position.x > 1.0f - 0.1f) t->position.x = 1.0f - 0.1f;
            if (t->position.y < -1.0f) t->position.y = -1.0f;
            if (t->position.y > 1.0f - 0.1f) t->position.y = 1.0f - 0.1f;
        }
    }
}
