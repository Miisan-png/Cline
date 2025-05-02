#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "imgui_helper.h"
#include "input.h"
#include "scene.h"
#include "game/test_scene.h"
#include "time.h"

GLFWwindow* window;

void ready() {
    glfwInit();
    window = glfwCreateWindow(800, 600, "Game", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    glewInit();
    input_set_window(window);
    input_bind("jump", GLFW_KEY_SPACE);
    input_bind("pause", GLFW_KEY_ESCAPE);
    InitImGui(window);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    scene_set(create_test_scene());
}

void process() {
    scene_process();
    RenderImGui();
}

bool should_close() {
    return glfwWindowShouldClose(window);
}

void update() {
    time_update();
    glfwPollEvents();
    glfwSwapBuffers(window);
}

void shutdown() {
    scene_shutdown();
    ShutdownImGui();
    glfwDestroyWindow(window);
    glfwTerminate();
}

GLFWwindow* get_window() {
    return window;
}
