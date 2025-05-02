#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "imgui_helper.h"
#include "input.h"

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
    input_set_window(window);
    input_bind("jump", GLFW_KEY_SPACE);
    input_bind("pause", GLFW_KEY_ESCAPE);
}


void process() {
    if (input_is_action_pressed("jump")) {
        glClearColor(0.2f, 0.6f, 0.2f, 1.0f); // Green if spacebar is held
    } else {
        glClearColor(0.1f, 0.1f, 0.15f, 1.0f); // Default background
    }
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
