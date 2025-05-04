
#include "core/resource_manager.h"
#define STB_IMAGE_IMPLEMENTATION
#include "core/stb_image.h"
#include <iostream>

std::unordered_map<std::string, GLuint> ResourceManager::m_Textures;

GLuint ResourceManager::LoadTexture(const std::string& file, bool alpha) {
    std::string name = file.substr(file.find_last_of("/\\") + 1);
    if (m_Textures.count(name)) return m_Textures[name];
    int w, h, nr;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(file.c_str(), &w, &h, &nr, 0);
    if (!data) return 0;
    GLenum fmt = (nr == 4 ? GL_RGBA : GL_RGB);
    GLuint tex;
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexImage2D(GL_TEXTURE_2D, 0, fmt, w, h, 0, fmt, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    stbi_image_free(data);
    m_Textures[name] = tex;
    return tex;
}

GLuint ResourceManager::GetTexture(const std::string& name) {
    return m_Textures.count(name) ? m_Textures[name] : 0;
}

void ResourceManager::Clear() {
    for (auto& kv : m_Textures) glDeleteTextures(1, &kv.second);
    m_Textures.clear();
}
