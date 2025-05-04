#pragma once
#include "ecs/entity.h"
#include <GL/glew.h>

struct Sprite {
    GLuint texture;
    float w;
    float h;
};

void sprite_add(Entity e, const char* file);
Sprite* sprite_get(Entity e);
void sprite_remove(Entity e);
