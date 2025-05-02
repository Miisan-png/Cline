#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "imgui_helper.h"

GLFWwindow* window;

void ready() {
    glfwInit();
    window = glfwCreateWindow(800, 600, "Game", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    glewInit();
    InitImGui(window);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}

void process() {
    glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    RenderImGui();
}

bool should_close() {
    return glfwWindowShouldClose(window);
}

void update() {
    glfwPollEvents();
    glfwSwapBuffers(window);
}

void shutdown() {
    ShutdownImGui();
    glfwDestroyWindow(window);
    glfwTerminate();
}

GLFWwindow* get_window() {
    return window;
}
