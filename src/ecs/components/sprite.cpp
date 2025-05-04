#include "ecs/components/sprite.h"
#include "core/resource_manager.h"
#include <unordered_map>

std::unordered_map<Entity, Sprite> s_Sprites;

void sprite_add(Entity e, const char* file) {
    GLuint tex = ResourceManager::LoadTexture(file);
    s_Sprites[e] = { tex, 1.0f, 1.0f };
}

Sprite* sprite_get(Entity e) {
    auto it = s_Sprites.find(e);
    return it == s_Sprites.end() ? nullptr : &it->second;
}

void sprite_remove(Entity e) {
    s_Sprites.erase(e);
}
