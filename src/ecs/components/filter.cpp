#include "ecs/components/filter.h"
#include "ecs/components/sprite.h"
#include <unordered_map>
#include <GL/glew.h>

static std::unordered_map<Entity, FilterMode> s_Filters;

void filter_add(Entity e, FilterMode mode) {
    s_Filters[e] = mode;
    Sprite* spr = sprite_get(e);
    if (!spr) return;
    glBindTexture(GL_TEXTURE_2D, spr->texture);
    GLint f = (mode == FILTER_NEAREST ? GL_NEAREST : GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, f);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, f);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void filter_remove(Entity e) {
    s_Filters.erase(e);
}

FilterMode filter_get(Entity e) {
    return s_Filters.count(e) ? s_Filters[e] : FILTER_LINEAR;
}
