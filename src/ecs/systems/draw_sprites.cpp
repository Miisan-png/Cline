#include "ecs/systems/draw_sprites.h"
#include "ecs/components/sprite.h"
#include "ecs/components/transform.h"
#include <GL/glew.h>

extern std::unordered_map<Entity, Sprite> s_Sprites;

void system_draw_sprites() {
    for (auto& kv : s_Sprites) {
        Entity e = kv.first;
        Sprite& spr = kv.second;
        auto xf = transform_get(e);
        if (!xf) continue;
        glBindTexture(GL_TEXTURE_2D, spr.texture);
        glBegin(GL_QUADS);
        float hw = spr.w/2;
        float hh = spr.h/2;
        float x = xf->position.x;
        float y = xf->position.y;
        glTexCoord2f(0,0); glVertex2f(x - hw, y - hh);
        glTexCoord2f(1,0); glVertex2f(x + hw, y - hh);
        glTexCoord2f(1,1); glVertex2f(x + hw, y + hh);
        glTexCoord2f(0,1); glVertex2f(x - hw, y + hh);
        glEnd();
    }
    glBindTexture(GL_TEXTURE_2D, 0);
}
