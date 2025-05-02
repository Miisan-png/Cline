#include "ecs/components/transform.h"
#include "ecs/components/collider.h"
#include <cstdio>

bool aabb_overlap(float ax, float ay, float aw, float ah,
                  float bx, float by, float bw, float bh) {
    return ax < bx + bw && ax + aw > bx &&
           ay < by + bh && ay + ah > by;
}

void system_collision_check() {
    for (Entity a = 1; a < 10000; ++a) {
        if (!transform_has(a) || !collider_has(a)) continue;
        auto* ta = transform_get(a);
        auto* ca = collider_get(a);
        float ax = ta->position.x + ca->offset.x;
        float ay = ta->position.y + ca->offset.y;
        float aw = ca->size.x;
        float ah = ca->size.y;

        for (Entity b = a + 1; b < 10000; ++b) {
            if (!transform_has(b) || !collider_has(b)) continue;
            auto* tb = transform_get(b);
            auto* cb = collider_get(b);
            float bx = tb->position.x + cb->offset.x;
            float by = tb->position.y + cb->offset.y;
            float bw = cb->size.x;
            float bh = cb->size.y;

            if (aabb_overlap(ax, ay, aw, ah, bx, by, bw, bh)) {
                printf("Entity %d collided with %d\n", a, b);
            }
        }
    }
}
