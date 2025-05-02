#include "ecs/components/transform.h"
#include "ecs/components/velocity.h"

void system_movement(float dt) {
    for (Entity e = 1; e < 10000; ++e) {
        if (transform_has(e) && velocity_has(e)) {
            auto* t = transform_get(e);
            auto* v = velocity_get(e);
            t->position = t->position + v->velocity * dt;
        }
    }
}
