#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "src/imgui_helper.h"

struct Particle {
    float x, y;
    float dx, dy;
    float r, g, b;
    float lifetime;
};

enum ParticleType { FIRE, SNOW, SMOKE };
ParticleType currentType = FIRE;

std::vector<Particle> particles;

void spawnParticle() {
    Particle p;
    p.x = 0.0f;
    p.y = 0.0f;

    switch (currentType) {
        case FIRE:
            p.dx = ((rand() % 100) - 50) / 500.0f;
            p.dy = (rand() % 100) / 200.0f;
            p.r = 1.0f; p.g = 0.4f; p.b = 0.1f;
            break;
        case SNOW:
            p.dx = ((rand() % 100) - 50) / 1000.0f;
            p.dy = -((rand() % 100) / 500.0f);
            p.r = p.g = p.b = 1.0f;
            break;
        case SMOKE:
            p.dx = ((rand() % 100) - 50) / 800.0f;
            p.dy = ((rand() % 100) / 600.0f);
            p.r = p.g = p.b = 0.5f;
            break;
    }

    p.lifetime = 1.0f;
    particles.push_back(p);
}

void updateParticles(float dt) {
    for (auto& p : particles) {
        p.x += p.dx;
        p.y += p.dy;
        p.lifetime -= dt;
    }
    particles.erase(
        std::remove_if(particles.begin(), particles.end(),
            [](const Particle& p) { return p.lifetime <= 0; }),
        particles.end());
}

void renderParticles() {
    glPointSize(4.0f);
    glBegin(GL_POINTS);
    for (const auto& p : particles) {
        glColor3f(p.r, p.g, p.b);
        glVertex2f(p.x, p.y);
    }
    glEnd();
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    if (!glfwInit()) return -1;
    GLFWwindow* window = glfwCreateWindow(800, 600, "Particles + ImGui", NULL, NULL);
    if (!window) return -1;

    glfwMakeContextCurrent(window);
    glewInit();

    InitImGui(window); // 👈 Initialize ImGui

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS) currentType = FIRE;
        if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS) currentType = SNOW;
        if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS) currentType = SMOKE;

        for (int i = 0; i < 10; i++) spawnParticle();
        updateParticles(0.016f); // ~60FPS

        glClearColor(0.05f, 0.05f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        renderParticles();
        RenderImGui(); // 👈 Show ImGui window

        glfwSwapBuffers(window);
    }

    ShutdownImGui(); // 👈 Cleanup
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
