#include "ecs/components/transform.h"
#include "core/draw.h"

void system_draw_transforms() {
    for (Entity e = 1; e < 10000; ++e) {
        if (transform_has(e)) {
            auto* t = transform_get(e);
            draw_rect(t->position.x, t->position.y, 0.1f, 0.1f, 0.8f, 0.8f, 0.2f);
        }
    }
}
