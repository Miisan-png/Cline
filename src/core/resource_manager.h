#pragma once
#include <string>
#include <unordered_map>
#include <GL/glew.h>
struct ResourceManager {
    static GLuint LoadTexture(const std::string& file, bool alpha = true);
    static GLuint GetTexture(const std::string& name);
    static void Clear();
private:
    static std::unordered_map<std::string, GLuint> m_Textures;
};
