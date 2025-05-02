#include "ecs/components/transform.h"
#include "ecs/components/collider.h"
#include <GL/glew.h>

void system_collision_draw() {
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(1, 1, 0);

    for (Entity e = 1; e < 10000; ++e) {
        if (transform_has(e) && collider_has(e)) {
            auto* t = transform_get(e);
            auto* c = collider_get(e);

            float x = t->position.x + c->offset.x;
            float y = t->position.y + c->offset.y;
            float w = c->size.x;
            float h = c->size.y;

            glBegin(GL_QUADS);
            glVertex2f(x, y);
            glVertex2f(x + w, y);
            glVertex2f(x + w, y + h);
            glVertex2f(x, y + h);
            glEnd();
        }
    }

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
